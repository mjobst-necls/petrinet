/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef TOKEN_H
#define TOKEN_H

#include "list"
#include "time.h"

namespace petrinet{

class TokenData;

class Token
{
public:
    Token();
    Token(const Token& other);

    bool isMergeable(const Token& other) const;
    Token* mergeWith(const Token& token);

    void addData(TokenData* tokenData);
    const std::list<TokenData*>& getTokenData() const { return data_; }

    time_t getTimestamp() const;

private:
    std::list<TokenData*> data_;
};

}

#endif // TOKEN_H
