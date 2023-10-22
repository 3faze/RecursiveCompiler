#pragma once

enum class Token_ty
{
    Plus,
    PlusEq,
    Minus,
    MinusEq,
    Mul,
    MulEq,
    Div,
    DivEq,
    Comma,
    Semicolon,
    Colon,
    LParen,
    RParen,
    LSquare,
    RSquare,
    LCurly,
    RCurly,
    LAngle,
    RAngle,
    DoubleLAngle,
    DoubleRAngle,
    LAngleEq,
    RAngleEq,
    Dot,
    Number,
    String,
    Identifier,
    Whitespace,
    Eof
};

struct Token
{
    Token_ty ty;
    int start_pos;
    int end_pos;
    std::string val;
};

#include <string>

class Tokenizer{
public:
    Token* tokenize(std::string src);

};

//Token* Tokenizer::tokenize(std::string src, int start_pos);
