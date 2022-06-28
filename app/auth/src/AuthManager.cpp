//
// Created by sajith on 6/28/22.
//

#include "auth/AuthManager.h"


namespace
{
    const types::Login dummyLogin{"John Doe"};
    const types::Password dummyPassword{"@12345"};
    const std::set<std::uint32_t> dummyTaxpayerIds{1, 2, 3, 4, 5, 5, 6, 8, 9, 10};
}

namespace auth
{
    AuthManger::AuthManger() : users{types::User{dummyLogin, dummyPassword, dummyTaxpayerIds}}
    {}

    bool AuthManger::authenticate(const types::Login &login, const types::Password &password) const
    {
        const auto itr = users.find(login);
        return itr != users.end() && itr->password.value == password.value;
    }

    bool AuthManger::isAuthorized(const types::Login &login, std::uint32_t taxpayer_id) const
    {
        const auto itr = users.find(login);
        return itr != users.end() && itr->taxpayers.count(taxpayer_id) > 0;
    }
}