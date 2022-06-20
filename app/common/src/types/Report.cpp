//
// Created by sajith on 6/20/22.
//

#include "types/Report.h"
#include <tuple>

namespace types
{
    bool operator==(const Report &lhs, const Report &rhs)
    {
        return std::tie(lhs.payer, lhs.tax, lhs.amount, lhs.year) == std::tie(rhs.payer, rhs.tax, rhs.amount, rhs.year);
    }
}
