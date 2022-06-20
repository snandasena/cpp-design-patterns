//
// Created by sajith on 6/20/22.
//

#ifndef DESIGN_PATTERNS_REPORT_H
#define DESIGN_PATTERNS_REPORT_H

#include <cstdint>
#include <string>

namespace types
{
    struct Report
    {
        const std::uint32_t payer;
        const std::string tax;
        const double amount;
        const std::uint16_t year;
    };

    bool operator==(const Report &, const Report &);
}


#endif //DESIGN_PATTERNS_REPORT_H
