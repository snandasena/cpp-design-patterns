//
// Created by sajith on 6/18/22.
//

#ifndef DESIGN_PATTERNS_PERSONADDRESSBUILDER_H
#define DESIGN_PATTERNS_PERSONADDRESSBUILDER_H

class PersonAddressBuilder : public PersonBuilderBase
{
    typedef PersonAddressBuilder Self;
public:
    PersonAddressBuilder(Person &person) : PersonBuilderBase(person) {

    }

};

#endif //DESIGN_PATTERNS_PERSONADDRESSBUILDER_H
