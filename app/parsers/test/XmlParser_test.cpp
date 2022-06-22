//
// Created by sajith on 6/22/22.
//

#include "parsers/XmlParser.h"

#include <gtest/gtest.h>
#include <optional>
#include <string>

#include "types/Report.h"

struct XmlParserTest : testing::Test
{
    parsers::XmlParser sut;
};

TEST_F(XmlParserTest, whenValidData_parseReportReturnsReport)
{
    const std::string xmlRequest{"<report>"
                                 "<payer>2</payer>"
                                 "<tax>VAT</tax>"
                                 "<amount>10</amount>"
                                 "<year>2020</year>"
                                 "</report>"};

    const std::optional<types::Report> parserReport = sut.parseReport(xmlRequest);
    const types::Report expectedReport{2, "VAT", 10, 2020};
    ASSERT_TRUE(parserReport);
    ASSERT_EQ(parserReport, expectedReport);
}



TEST_F(XmlParserTest, whenMissingFields_parseReportReturnsNull)
{
    const std::string xmlReport = "<report><payer>2</payer><year>2020</year></report>";
    ASSERT_EQ(sut.parseReport(xmlReport), std::nullopt);
}

TEST_F(XmlParserTest, whenEmptyReport_parseReportReturnsNull)
{
    const std::string xmlReport = "";
    ASSERT_EQ(sut.parseReport(xmlReport), std::nullopt);
}

TEST_F(XmlParserTest, whenInvalidXml_parseReportReturnsNull)
{
    const std::string xmlReport = "<<report>>";
    ASSERT_EQ(sut.parseReport(xmlReport), std::nullopt);
}

TEST_F(XmlParserTest, whenNumericDataInvalid_parseReportReturnsNull)
{
    const std::string xmlReport = "<report><payer>Two</payer><tax>VAT</tax><amount>One"
                                  "</amount><year>Three</year></report>";
    ASSERT_EQ(sut.parseReport(xmlReport), std::nullopt);
}

TEST_F(XmlParserTest, whenValidData_parseCredentialsReturnsUser)
{
    const std::string xmlReport = "<credentials><login>Jhon Doe</login>"
                                  "<password>123</password></credentials>";
    const std::optional<types::User> parsedUser = sut.parseCredentials(xmlReport);
    ASSERT_TRUE(parsedUser);
    ASSERT_EQ(parsedUser->login.value, std::string("Jhon Doe"));
    ASSERT_EQ(parsedUser->password.value, std::string("123"));
}

TEST_F(XmlParserTest, whenMissingFields_parseCredentialsReturnsNull)
{
    const std::string xmlReport = "<credentials><login>Jhon Doe</login></credentials>";
    const std::optional<types::User> parsedUser = sut.parseCredentials(xmlReport);
    ASSERT_EQ(parsedUser, std::nullopt);
}