/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#include "Token.h"
#include "TokenData.h"

namespace petrinet{

Token::Token()
{

}

Token::Token(const Token& other)
{
    for (std::list<TokenData*>::const_iterator it = other.data_.begin(); it!=other.data_.end(); ++it){
        data_.push_back((*it)->clone());
    }
}

bool Token::isMergeable(const Token& other) const
{
    bool mergeable = true;

    std::list<TokenData*>::const_iterator oit = other.data_.begin();

    for (std::list<TokenData*>::const_iterator it = data_.begin(); it!=data_.end(); ++it){
        if( oit == other.data_.end())
            break;

        // check if is same type
        if( !(*oit)->isMergeable(*(*it))){
            mergeable = false;
            break;
        }

        oit++;
    }

    return mergeable;
}

Token* Token::mergeWith(const Token& token){
    // merge data with other token's data

    data_.back()->setTimestamp(token.data_.back()->getTimestamp());
    return this;
}

// try to merge data if possible. if not, simply add data
void Token::addData(TokenData* tokenData)
{
    data_.push_back(tokenData);
}

time_t Token::getTimestamp() const
{
    time_t timestamp = 0;

    if( data_.size() > 0 )
        timestamp = data_.back()->getTimestamp();

    return timestamp;
}

}
