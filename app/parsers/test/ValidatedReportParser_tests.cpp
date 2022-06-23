//
// Created by sajith on 6/22/22.
//

#include "parsers/ValidatedReportParser.h"

#include <gtest/gtest.h>
#include <optional>
#include <string>
#include <vector>

#include "constants/Constants.h"
#include "nlohmann/json.hpp"
#include "parsers/JsonParser.h"
#include "parsers/XmlParser.h"
#include "types/Report.h"

using json = nlohmann::json;

namespace parsers
{
    struct ValidatedReportParserTest : testing::Test
    {
        const ValidatedReportParser<JsonParser> sut;
        const std::string taxName = *constants::validTaxNames.begin();

        const std::string validReport =
                nlohmann::to_string(json{{"payer",  1},
                                         {"tax",    taxName},
                                         {"amount", 1000},
                                         {"year",   2020}});

        const std::vector<std::string> invalidReports = {
                to_string(json{{"payer",  1},
                               {"tax",    taxName},
                               {"amount", 0.0},
                               {"year",   2020}}),
                to_string(json{{"payer",  1},
                               {"tax",    taxName},
                               {"amount", 1000},
                               {"year",   2222}}),
                to_string(json{{"payer",  1},
                               {"tax",    "Unknown tax"},
                               {"amount", 0},
                               {"year",   2020}}),
        };
    };

    TEST_F(ValidatedReportParserTest, reportValidationSucceeds)
    {
        ASSERT_NE(sut.parseReport(validReport), std::nullopt);
    }

    TEST_F(ValidatedReportParserTest, reportValidationFails)
    {
        for (const auto &item: invalidReports)
        {
            ASSERT_EQ(sut.parseReport(item), std::nullopt);
        }
    }
}