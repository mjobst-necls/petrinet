/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef ARC_H
#define ARC_H

#include "PetriNetObject.h"

namespace petrinet{

class ConnectableElement;

class Arc : public PetriNetObject
{
public:
    Arc();
    ~Arc();

    void setLink(ConnectableElement* source, ConnectableElement* target);
    void removeLink();

    ConnectableElement* getSource() const { return source_; }
    ConnectableElement* getTarget() const { return target_; }

private:
    ConnectableElement* source_;
    ConnectableElement* target_;
};

}

#endif // ARC_H
