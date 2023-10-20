#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

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

class Tokenizer
{
public:
    char nth(int n, std::string src)
    {
        if (n <= src.size())
        {

            return src[n];
        }
        else
        {
            return '\0';
        }
    }

    bool is_ident_char(char c, bool first)
    {
        if (first == true)
        {
            if (isalpha(c))
            {
                return true;
            }
            else
            {
                if (c == '_')
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else if (first == false)
        {
            if (isalnum(c))
            {
                return true;
            }
            else
            {
                if (c == '_')
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }

    char get_next(int pos, std::string src)
    {
        return nth(pos + 1, src);
    }

    Token* tokenize(std::string src, int start_pos)
    {
        Token* curr_token = new Token;
        for (int pos = start_pos; pos <= src.size(); pos++)
        {
            char c = nth(pos, src);
            Token_ty curr_type;
            curr_token->start_pos = pos;
            if (c == '+')
            {
                if (get_next(pos, src) == '=')
                {
                    curr_type = Token_ty::PlusEq;
                    curr_token->ty = curr_type;
                    curr_token->end_pos = pos + 1;
                    return curr_token;
                }
                curr_type = Token_ty::Plus;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '-')
            {
                if (get_next(pos, src) == '=')
                {
                    curr_type = Token_ty::MinusEq;
                    curr_token->ty = curr_type;
                    curr_token->end_pos = pos + 1;
                    return curr_token;
                }
                curr_type = Token_ty::Minus;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '*')
            {
                if (get_next(pos, src) == '=')
                {
                    curr_type = Token_ty::MulEq;
                    curr_token->ty = curr_type;
                    curr_token->end_pos = pos + 1;
                    return curr_token;
                }
                curr_type = Token_ty::Mul;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '/')
            {
                if (get_next(pos, src) == '=')
                {
                    curr_type = Token_ty::DivEq;
                    curr_token->ty = curr_type;
                    curr_token->end_pos = pos + 1;
                    return curr_token;
                }
                curr_type = Token_ty::Div;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == ',')
            {
                curr_type = Token_ty::Comma;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == ';')
            {
                curr_type = Token_ty::Semicolon;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == ':')
            {
                curr_type = Token_ty::Colon;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '(')
            {
                curr_type = Token_ty::LParen;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == ')')
            {
                curr_type = Token_ty::RParen;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '[')
            {
                curr_type = Token_ty::LSquare;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == ']')
            {
                curr_type = Token_ty::RSquare;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '{')
            {
                curr_type = Token_ty::LCurly;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '}')
            {
                curr_type = Token_ty::RCurly;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '<')
            {
                if (get_next(pos, src) == '<')
                {
                    curr_type = Token_ty::DoubleLAngle;
                    curr_token->ty = curr_type;
                    curr_token->end_pos = pos + 1;
                    return curr_token;
                } else if (get_next(pos, src) == '=')
                {
                    curr_type = Token_ty::LAngleEq;
                    curr_token->ty = curr_type;
                    curr_token->end_pos = pos + 1;
                    return curr_token;
                }
                curr_type = Token_ty::LAngle;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '>')
            {
                if (get_next(pos, src) == '>')
                {
                    curr_type = Token_ty::DoubleRAngle;
                    curr_token->ty = curr_type;
                    curr_token->end_pos = pos + 1;
                    return curr_token;
                } else if (get_next(pos, src) == '=')
                {
                    curr_type = Token_ty::RAngleEq;
                    curr_token->ty = curr_type;
                    curr_token->end_pos = pos + 1;
                    return curr_token;
                }
                curr_type = Token_ty::RAngle;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (c == '.')
            {
                curr_type = Token_ty::Dot;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
            if (isdigit(c))
            {
                curr_type = Token_ty::Number;
                curr_token->ty = curr_type;
                int temp_pos = pos;
                while (isdigit(get_next(temp_pos, src)) || get_next(temp_pos, src) == '.')
                {
                    temp_pos++;
                }
                curr_token->end_pos = temp_pos; // Update end_pos to temp_pos
                std::vector<char> val(src.begin() + pos, src.begin() + temp_pos + 1);
                std::string ret_val(val.begin(), val.end());
                pos = temp_pos;
                curr_token->val = ret_val;
                return curr_token;
            }
            if (c == '\'')
            {
                curr_type = Token_ty::String;
                curr_token->ty = curr_type;
                int temp_pos = pos;
                while (get_next(temp_pos, src) != '\'')
                {
                    temp_pos++;
                }
                curr_token->end_pos = temp_pos; // Update end_pos to temp_pos
                std::vector<char> val(src.begin() + pos, src.begin() + temp_pos + 1);
                std::string ret_val(val.begin(), val.end());
                ret_val = ret_val.substr(1);
                pos = temp_pos;
                curr_token->val = ret_val;
                return curr_token;
            }
            if (is_ident_char(c, true))
            {
                curr_type = Token_ty::Identifier;
                curr_token->ty = curr_type;
                int temp_pos = pos;
                while (is_ident_char(get_next(temp_pos, src), false))
                {
                    temp_pos++;
                }
                curr_token->end_pos = temp_pos; // Update end_pos to temp_pos
                std::vector<char> val(src.begin() + pos, src.begin() + temp_pos + 1);
                std::string ret_val(val.begin(), val.end());
                pos = temp_pos;
                curr_token->val = ret_val;
                return curr_token;
            }
            if (c == ' ')
            {
                curr_type = Token_ty::Whitespace;
                curr_token->ty = curr_type;
                curr_token->end_pos = pos;
                return curr_token;
            }
        }
    }
};

int main()
{
    Tokenizer lexer;
    Token* token = lexer.tokenize("abcde", 0);
    std::cout << token->start_pos << " " << token->end_pos << " " << token->val << std::endl;
    return 0;
}
