//
// Created by sajith on 6/13/22.
//

#ifndef DESIGN_PATTERNS_PERSONBUILDER_H
#define DESIGN_PATTERNS_PERSONBUILDER_H

#include "Person.h"

class PersonJobBuilder;

class PersonAddressBuilder;

class PersonBuilderBase
{
protected:
    Person &person;

public:
    PersonBuilderBase(Person &person);

    PersonAddressBuilder lives() const;

    PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
    Person p;
public:
    PersonBuilder();

    operator Person() const
    {
        return std::move(person);
    }
};


#endif //DESIGN_PATTERNS_PERSONBUILDER_H
