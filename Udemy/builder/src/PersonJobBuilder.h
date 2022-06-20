//
// Created by sajith on 6/18/22.
//

#ifndef DESIGN_PATTERNS_PERSONJOBBUILDER_H
#define DESIGN_PATTERNS_PERSONJOBBUILDER_H

class PersonJobBuilder : public PersonBuilderBase
{
    typedef PersonJobBuilder Self;

public:
    explicit PersonJobBuilder(Person &person) : PersonBuilderBase(person) {}

    Self &at(std::string company_name)
    {
        person.company_name = company_name;
        return *this;
    }

    Self &as_a(std::string position)
    {
        person.position = position;
        return *this;
    }

    Self &earning(int annual_income)
    {
        person.annual_income = annual_income;
        return *this;
    }
};

#endif //DESIGN_PATTERNS_PERSONJOBBUILDER_H
