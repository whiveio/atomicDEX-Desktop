/******************************************************************************
 * Copyright © 2013-2024 The Komodo Platform Developers.                      *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * Komodo Platform software, including this file may be copied, modified,     *
 * propagated or distributed except according to the terms contained in the   *
 * LICENSE file                                                               *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

#pragma once

#include <optional>
#include <string>

//! Deps
#include <nlohmann/json_fwd.hpp>

//! Our Headers
#include "atomicdex/api/kdf/generic.error.hpp"
#include "atomicdex/api/kdf/transaction.data.hpp"

namespace atomic_dex::kdf
{
    struct withdraw_status_request
    {
        int         task_id;
    };

    struct withdraw_status_answer
    {
        std::optional<transaction_data>     result;
        std::optional<generic_answer_error> error;
        std::string                         raw_result;      ///< internal
        int                                 rpc_result_code; ///< internal
    };

    void to_json(nlohmann::json& j, const withdraw_status_request& request);
    void from_json(const nlohmann::json& j, withdraw_status_answer& answer);
}

namespace atomic_dex
{
    using t_withdraw_status_request = kdf::withdraw_status_request;
    using t_withdraw_status_answer = kdf::withdraw_status_answer;
} // namespace atomic_dex
