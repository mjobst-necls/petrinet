/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "TokenData.h"

namespace petrinet{

TokenData::TokenData()
{

}

TokenData::TokenData(const TokenData& other)
    : TimestampedElement(other),
      transition_(other.transition_)
{

}

}
