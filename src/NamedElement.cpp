/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "NamedElement.h"

namespace petrinet{

NamedElement::NamedElement()
{

}

NamedElement::NamedElement(const std::string& name)
    : name_(name)
{

}

}
