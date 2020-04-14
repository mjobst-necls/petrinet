/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef NAMEDELEMENT_H
#define NAMEDELEMENT_H

#include "string"

namespace petrinet{

class NamedElement
{
public:
    NamedElement();
    NamedElement(const std::string& name);

    const std::string& getName() { return name_; }
    void setName(const std::string& name) { name_ = name; }

private:
    std::string name_;
};

}

#endif // NAMEDELEMENT_H
