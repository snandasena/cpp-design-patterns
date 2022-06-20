//
// Created by sajith on 6/20/22.
//

#ifndef DESIGN_PATTERNS_REPORTFORMAT_H
#define DESIGN_PATTERNS_REPORTFORMAT_H

#include <iosfwd>

namespace types
{
    enum class ReportFormat
    {
        Json,
        Xml
    };
}

std::istream &operator>>(std::istream &, types::ReportFormat &);

#endif //DESIGN_PATTERNS_REPORTFORMAT_H
