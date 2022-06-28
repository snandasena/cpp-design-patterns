//
// Created by sajith on 6/28/22.
//

#ifndef DESIGN_PATTERNS_IAUTHORIZATION_H
#define DESIGN_PATTERNS_IAUTHORIZATION_H

#include "types/User.h"

namespace auth
{
    class IAuthorization
    {
    public:

        virtual  ~IAuthorization() = default;

        virtual bool isAuthorized(const types::Login &, std::uint32_t) const = 0;
    };
}
#endif //DESIGN_PATTERNS_IAUTHORIZATION_H
