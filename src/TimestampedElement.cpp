/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "TimestampedElement.h"

namespace petrinet{

TimestampedElement::TimestampedElement()
    : timestamp_(time(0))
{

}

TimestampedElement::TimestampedElement(const TimestampedElement& other)
    : timestamp_(other.timestamp_)
{
}

}
