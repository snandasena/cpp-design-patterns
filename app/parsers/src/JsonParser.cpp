//
// Created by sajith on 6/20/22.
//

#include "parsers/JsonParser.h"

#include <iostream>
#include <stdexcept>

#include "nlohmann/json.hpp"

namespace parsers
{
    std::optional<types::Report> JsonParser::parseReport(const std::string &rawReport) const try
    {
        if (const auto json = nlohmann::json::parse(rawReport); !json.empty())
        {
            return types::Report{
                    json.at("payer"),
                    json.at("tax"),
                    json.at("amount"),
                    json.at("year")};
        }
        return std::nullopt;
    } catch (const std::exception &e)
    {
        std::cerr << __FILE__ << ' ' << e.what() << '\n';
        return std::nullopt;
    }

    std::optional<types::User> JsonParser::parseCredentials(const std::string &rawCredentials) const try
    {
        if (const auto json = nlohmann::json::parse(rawCredentials); !json.empty())
        {
            return types::User
                    {
                            {json.at("login")},
                            {json.at("password")},
                            {}
                    };
        }
        return std::nullopt;

    } catch (const std::exception &e)
    {
        std::cerr << __FILE__ << ' ' << e.what() << '\n';
        return std::nullopt;
    }
}