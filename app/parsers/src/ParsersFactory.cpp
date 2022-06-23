//
// Created by sajith on 6/22/22.
//

#include "parsers/ParsersFactory.h"
#include "parsers/JsonParser.h"
#include "parsers/ValidatedReportParser.h"
#include "parsers/XmlParser.h"

namespace parsers
{
    ParserFactory::ParserFactory(const types::ReportFormat rF) : reportFormat{rF} {}

    std::unique_ptr<IReportParser> ParserFactory::createReportParser() const
    {
        switch (reportFormat)
        {
            case types::ReportFormat::Json:
                return std::make_unique<parsers::ValidatedReportParser<JsonParser>>();

            case types::ReportFormat::Xml:
                return std::make_unique<parsers::ValidatedReportParser<XmlParser>>();
        }
        return nullptr;
    }

    std::unique_ptr<ICredentialsParser> ParserFactory::createCredentialParser() const
    {
        switch (reportFormat)
        {
            case types::ReportFormat::Json:
                return std::make_unique<JsonParser>();
            case types::ReportFormat::Xml:
                return std::make_unique<XmlParser>();
        }
        return nullptr;
    }
}