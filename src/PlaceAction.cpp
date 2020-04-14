/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "PlaceAction.h"

namespace petrinet{

PlaceAction::PlaceAction()
    : executeLater_(false)
{

}

PlaceAction::PlaceAction(const PlaceAction& other)
    : executeLater_(other.executeLater_)
{

}

PlaceAction::~PlaceAction()
{

}

}
