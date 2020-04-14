/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "Transition.h"
#include "Arc.h"
#include "Place.h"
#include "PetriNet.h"
#include "AbstractTransitionHelper.h"
#include "TransitionAction.h"
#include "TokenData.h"
#include "list"
#include "Token.h"
#include "AbstractTransitionCondition.h"

namespace petrinet{

Transition::Transition()
    : petriNet_(NULL)
{

}

Transition::Transition(const std::string& name)
    : NamedElement(name),
      petriNet_(NULL)
{

}

void Transition::setPetriNet(PetriNet* petriNet)
{
    petriNet_ = petriNet;
}

void Transition::setAction(TransitionAction* action)
{
    action_ = action;
}

bool Transition::isMatching(const AbstractPetriNetQuery& query) const
{
    return petriNet_->getTransitionHelper()->isMatching(*this, query);
}

bool Transition::isActive() const
{
    bool isActive_ = true;

    for( unsigned int i = 0; i < incoming_.size(); i++ ){
        petrinet::Place* p = static_cast<petrinet::Place*>(incoming_.at(i)->getSource());

        if( !p->hasTokens() ){
            isActive_ = false;
            break;
        }
    }

    return isActive_;
}

std::list<petrinet::PlaceAction*> Transition::trigger(const AbstractPetriNetQuery& query)
{
    return petriNet_->getTransitionHelper()->trigger(*this, query);
}

TokenData* Transition::getTokenData(const AbstractPetriNetQuery& query)
{
    if( action_ ){
        TokenData* data = action_->getTransitionTokenData(query);
        data->setTransition(this);
        return data;
    }

    return NULL;
}

bool Transition::hasBackwardsArc(const petrinet::Place& place) const
{
    for( unsigned int i = 0; i < outgoing_.size(); i++){
        if( outgoing_.at(i)->getTarget() == &place ){
            return true;
        }
    }

    return false;
}

bool Transition::hasTowardsArc(const petrinet::Place& place) const
{
    for( unsigned int i = 0; i < incoming_.size(); i++){
        if( incoming_.at(i)->getSource() == &place ){
            return true;
        }
    }

    return false;
}

void Transition::addCondition(const AbstractTransitionCondition* condition)
{
    conditions_.push_back(condition);
}

bool Transition::checkConditions(const Token& token, const petrinet::TokenData& tokenDataNew) const
{
    for (auto it = std::begin(conditions_); it!=std::end(conditions_); ++it){
        for( auto itt = std::begin(token.getTokenData()); itt!=std::end(token.getTokenData()); ++itt){
            if( (*itt)->getTransition() == (*it)->getTransition() ){
                // the value has to match
                if( ! (*it)->isFullfilled(*(*itt), tokenDataNew) ){
                    return false;
                }
            }
        }
    }

    return true;
}

}
