/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "Arc.h"
#include "ConnectableElement.h"

namespace petrinet{

Arc::Arc()
    : source_(0), target_(0)
{

}

Arc::~Arc()
{
    removeLink();
}

void Arc::removeLink()
{
    if( source_ ){
        source_->removeOutgoing(this);
        source_ = 0;
    }

    if( target_ ){
        target_->removeIncoming(this);
        target_ = 0;
    }
}

void Arc::setLink(ConnectableElement* source, ConnectableElement* target)
{
    source_ = source;
    source_->addOutgoing(this);
    target_ = target;
    target_->addIncoming(this);
}

}
