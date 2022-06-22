//
// Created by sajith on 6/20/22.
//

#ifndef DESIGN_PATTERNS_IREPORTPARSER_H
#define DESIGN_PATTERNS_IREPORTPARSER_H

#include <optional>
#include <string>

#include "types/Report.h"

namespace parsers
{
    class IReportParser
    {
    public:
        virtual ~IReportParser() = default;

        virtual std::optional<types::Report> parseReport(const std::string &) const = 0;
    };
}

#endif //DESIGN_PATTERNS_IREPORTPARSER_H
