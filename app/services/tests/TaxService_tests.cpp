//
// Created by sajith on 7/4/22.
//



#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <optional>
#include <string>

#include "constants/Constants.h"
#include "AuthorizationMock.h"
#include "ReportParserMock.h"
#include "types/Report.h"
#include "types/User.h"
#include "../include/services/TaxService.h"


using namespace constants;

using ::testing::Return;
using ::testing::StrictMock;

struct TaxServiceTests : testing::Test
{
    TaxServiceTests() : sut(user, authMock, parserMock)
    {}


    types::User user;
    StrictMock<auth::AuthorizationMock> authMock;
    StrictMock<parsers::ReportParserMock> parserMock;
    services::TaxService sut;

    const std::string rawReport = "{}";
    const types::Report report{10, "VAT", 20, 2020};

};

TEST_F(TaxServiceTests, whenReportParsingAndAuthorizationSucceed_returnOK)
{
    EXPECT_CALL(authMock, isAuthorized(user.login, report.payer)).WillOnce(Return(true));
    EXPECT_CALL(parserMock, parseReport(rawReport)).WillOnce(Return(report));
    ASSERT_EQ(sut.onReportRequest(rawReport),OK);
}
