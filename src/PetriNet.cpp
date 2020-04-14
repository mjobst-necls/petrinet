/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "PetriNet.h"
#include "Arc.h"
#include "Place.h"
#include "Token.h"
#include "Transition.h"


namespace petrinet{

PetriNet::PetriNet()
{

}

void PetriNet::addPlace(petrinet::Place* place, bool isInitial)
{
    places_.push_back(place);

    if( isInitial ){
        initialStates_.push_back(place);
        place->addToken(new petrinet::Token());
    }
}

void PetriNet::addTransition(petrinet::Transition* transition)
{
    transition->setPetriNet(this);
    transitions_.push_back(transition);

    // check if is always transition
    // add always transition
    //if( transition->getAction() == )
}

void PetriNet::addArc(petrinet::Arc* arc)
{
    arcs_.push_back(arc);
}

void PetriNet::addArc(petrinet::ConnectableElement* source, petrinet::ConnectableElement* target)
{
    petrinet::Arc* arc = new petrinet::Arc();
    arc->setLink(source, target);
    arcs_.push_back(arc);
}

}
