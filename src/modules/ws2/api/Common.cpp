/*
    Copyright (C) 2014-2016 Leosac

    This file is part of Leosac.

    Leosac is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Leosac is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "modules/ws2/api/Common.hpp"

namespace Leosac
{
namespace Module
{
namespace WS2
{
namespace API
{
boost::optional<json> get_leosac_version(const json &, ReqCtx)
{
    json ret;
    ret["version"] = getVersionString();
    return ret;
}

boost::optional<json> get_leosac_version_coro(const json &, ReqCtx rctx,
                                              boost::asio::yield_context yc)
{
    json ret;
    ret["version"] = getVersionString();
    boost::asio::steady_timer t(rctx.io_service_);

    t.expires_from_now(std::chrono::milliseconds(1000));
    t.async_wait(yc);

    return ret;
}
}
}
}
}
