//
// Created by sajith on 6/21/22.
//

#ifndef DESIGN_PATTERNS_VALIDATEDREPORTPARSER_H
#define DESIGN_PATTERNS_VALIDATEDREPORTPARSER_H

#include "parsers/IReportParser.h"

#include <type_traits>


namespace parsers
{
    template<typename BaseReportParser>
    class ValidatedReportParser : public BaseReportParser
    {
    public:
        static_assert(std::is_base_of<IReportParser, BaseReportParser>::value);

        std::optional<types::Report> parseReport(const std::string &) const override;
    };
}

#endif //DESIGN_PATTERNS_VALIDATEDREPORTPARSER_H
