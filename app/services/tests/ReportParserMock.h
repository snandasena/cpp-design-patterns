//
// Created by sajith on 7/4/22.
//

#ifndef DESIGN_PATTERNS_REPORTPARSERMOCK_H
#define DESIGN_PATTERNS_REPORTPARSERMOCK_H

#include "parsers/IReportParser.h"

#include <gmock/gmock.h>

namespace parsers
{
    class ReportParserMock : public IReportParser
    {
    public:
        MOCK_CONST_METHOD1(parseReport, std::optional<types::Report>(const std::string&));
    };
}

#endif //DESIGN_PATTERNS_REPORTPARSERMOCK_H
