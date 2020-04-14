/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "Place.h"
#include "Token.h"

#include "PlaceAction.h"

namespace petrinet{

Place::Place(const std::string& name, int timeout)
    : NamedElement(name),
      timeout_(timeout)
{

}

const std::list<Token*>& Place::getTokens() const
{
    return tokens_;
}

void Place::addToken(Token* token)
{
    tokens_.push_back(token);
}

std::list<PlaceAction*> Place::addToken(Token* token, TokenData* tokenData)
{
    bool merged = false;

    token->addData(tokenData);

    for (std::list<Token*>::iterator it = tokens_.begin(); it!=tokens_.end(); ++it){
        if( (*it)->isMergeable(*token)){
            (*it)->mergeWith(*token);
            merged = true;
        }
    }

    if( !merged ){
        addToken(token);
    }

    std::list<PlaceAction*> actions;

    for (std::list<PlaceAction*>::iterator it = actions_.begin(); it!=actions_.end(); ++it){
        PlaceAction* action = (*it)->create(*tokenData);

        if( action )
            actions.push_back(action);
    }

    return actions;
}

bool Place::hasTokens() const
{
    return tokens_.size() > 0;
}

void Place::removeAllTokens()
{
    //qDeleteAll(tokens_);
}

Token* Place::takeLastToken(){
    Token* t = tokens_.back();
    tokens_.pop_back();
    return t;
}

void Place::merge(TokenData* other, TokenData* tokenData)
{

}

void Place::merge(Place& other, TokenData* tokenData)
{
    /*for( int i = 0; i < other.getTokens().length(); i++){

        bool merged = false;

        for( int j = 0; j < getTokens().length(); j++ ){

            if( getTokens().at(j)->isMergeable(*other.getTokens().at(i)) )
            {
                getTokens().at(j)->mergeWith(*other.getTokens().at(i));
                merged = true;
                break;
            }
        }

        if (!merged){
            Token* t = new Token(*other.getTokens().at(i));
            t->addData(tokenData);
            tokens_.append(t);
        }
    }

    other.removeAllTokens();*/

    if( getTokens().size() > 0 ){
        // merge
    }
}

void Place::addAction(PlaceAction* action)
{
    actions_.push_back(action);
}

void Place::tokenTimeout()
{
    if( timeout_ <=  0)
        return;

    time_t current_time;
    time(&current_time);

    std::list<Token*> tokensRemove_;

    for (std::list<Token*>::iterator it = tokens_.begin(); it!=tokens_.end(); ++it){
        if( (*it)->getTimestamp() + timeout_ <= current_time ){
            tokensRemove_.push_back(*it);
        }
    }

    for (std::list<Token*>::iterator it = tokensRemove_.begin(); it!=tokensRemove_.end(); ++it){
        tokens_.remove(*it);
    }
}

}
