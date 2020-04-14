/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "ConnectableElement.h"

namespace petrinet{

ConnectableElement::ConnectableElement()
{

}

void ConnectableElement::addOutgoing(Arc* a)
{
    outgoing_.push_back(a);
}

void ConnectableElement::addIncoming(Arc* a)
{
    incoming_.push_back(a);
}

void ConnectableElement::removeOutgoing(Arc* a)
{
    //outgoing_.remove(a);
}

void ConnectableElement::removeIncoming(Arc* a)
{
    //incoming_.(a);
}

}
