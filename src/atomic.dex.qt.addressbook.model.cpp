/******************************************************************************
 * Copyright © 2013-2019 The Komodo Platform Developers.                      *
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

//! PCH
#include "atomic.dex.pch.hpp"

//! Project headers
#include "atomic.dex.qt.addressbook.model.hpp"

//! Addressbook contents model
namespace atomic_dex
{
    qt_contact_contents_model::qt_contact_contents_model(QObject* parent) noexcept : QObject(parent)
    {
        spdlog::debug("{} l{} f[{}]", __FUNCTION__, __LINE__, fs::path(__FILE__).filename().string());
        spdlog::debug("qt_contact_contents_model created");
    }

    qt_contact_contents_model::~qt_contact_contents_model() noexcept
    {
        spdlog::debug("{} l{} f[{}]", __FUNCTION__, __LINE__, fs::path(__FILE__).filename().string());
        spdlog::debug("qt_contact_contents_model destroyed");
    }

    QString
    atomic_dex::qt_contact_contents_model::get_contact_name() const noexcept
    {
        return m_contact_name;
    }

    void
    atomic_dex::qt_contact_contents_model::set_contact_name(const QString& contact_name) noexcept
    {
        m_contact_name = contact_name;
        emit contactNameChanged();
    }
} // namespace atomic_dex

//! Addressbook model
namespace atomic_dex
{
    addressbook_model::addressbook_model(atomic_dex::qt_wallet_manager& wallet_manager_, QObject* parent) noexcept :
        QObject(parent), m_wallet_manager(wallet_manager_)
    {
        spdlog::debug("{} l{} f[{}]", __FUNCTION__, __LINE__, fs::path(__FILE__).filename().string());
        spdlog::debug("addressbook model created");
    }

    addressbook_model::~addressbook_model() noexcept
    {
        spdlog::debug("{} l{} f[{}]", __FUNCTION__, __LINE__, fs::path(__FILE__).filename().string());
        spdlog::debug("addressbook model destroyed");
    }

    QList<QObject*>
    atomic_dex::addressbook_model::get_contents() const noexcept
    {
        return m_contact_contents;
    }
} // namespace atomic_dex