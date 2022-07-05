//
// Created by sajith on 7/4/22.
//

#ifndef DESIGN_PATTERNS_AUTHORIZATIONMOCK_H
#define DESIGN_PATTERNS_AUTHORIZATIONMOCK_H

#include "auth/IAuthorization.h"

#include <gmock/gmock.h>


namespace auth
{
    class AuthorizationMock : public IAuthorization
    {
    public:
        MOCK_CONST_METHOD2(isAuthorized, bool(const types::Login &, std::uint32_t));
    };
}
#endif //DESIGN_PATTERNS_AUTHORIZATIONMOCK_H
