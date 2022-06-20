//
// Created by sajith on 6/13/22.
//

#ifndef DESIGN_PATTERNS_PERSON_H
#define DESIGN_PATTERNS_PERSON_H

#include <string>
#include <ostream>

class PersonBuilder;
class PersonAddressBuilder;

class Person
{
    std::string street_address;
    std::string post_code;
    std::string city;
    std::string company_name;
    std::string position;

    int annual_income{0};

public:
    static PersonBuilder create();

    Person(Person &&other)
            : street_address{move(other.street_address)},
              post_code{move(other.post_code)},
              city{move(other.city)},
              company_name{move(other.company_name)},
              position{move(other.position)},
              annual_income{other.annual_income}
    {
    }

    Person &operator=(Person &&other)
    {
        if (this == &other)
            return *this;
        street_address = move(other.street_address);
        post_code = move(other.post_code);
        city = move(other.city);
        company_name = move(other.company_name);
        position = move(other.position);
        annual_income = other.annual_income;
        return *this;
    }

    friend class PersonBuilder;

    friend class PersonJobBuilder;

    friend class PersonAddressBuilder;

    friend std::ostream &operator<<(std::ostream &os, const Person &obj)
    {
        return os
                << "street_address: " << obj.street_address
                << " post_code: " << obj.post_code
                << " city: " << obj.city
                << " company_name: " << obj.company_name
                << " position: " << obj.position
                << " annual_income: " << obj.annual_income;
    }
};


#endif //DESIGN_PATTERNS_PERSON_H
