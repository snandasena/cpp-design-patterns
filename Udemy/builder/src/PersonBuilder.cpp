//
// Created by sajith on 6/13/22.
//

#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"


PersonBuilderBase::PersonBuilderBase(Person &person) : person(person) {}

PersonBuilder::PersonBuilder() : PersonBuilderBase(p) {}

PersonAddressBuilder PersonBuilder::lives() const
{
    return PersonAdressBuilder{person};
}

PersonJobBuilder PersonBuilder::works() const
{
    return PersonJobBuilder{person};
}
