//
// Created by sajith on 6/13/22.
//

#ifndef DESIGN_PATTERNS_PERSON_H
#define DESIGN_PATTERNS_PERSON_H

#include <string>

class PersonBuilder;

class Person
{
    std::string street_address;
    std::string post_code;
    std::string city;
    std::string company_name;
    std::string position;

    int annual_income{0};

    static PersonBuilder create();

    friend class PersonBuilder;

    friend class PersonJobBuilder;

    friend class PersonAdressBuilder;


};


#endif //DESIGN_PATTERNS_PERSON_H
