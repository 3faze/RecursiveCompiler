#include <iostream>
#include "lexer.h"

int main() {

    Tokenizer lexer;
    std::string src = "print('hello world');";
    int curr_loc = 0;
    int token_start = 0;

    while (true) {
        if (curr_loc < src.size()) {
            std::cout << src << std::endl;
            Token* token = lexer.tokenize(src);
            curr_loc += token->end_pos;
            src = src.substr(curr_loc + 1);

        } else {
            break;
        }
    }
    //Token* token = lexer.tokenize("abcde", 0);
    //std::cout << token->start_pos << " " << token->end_pos << " " << token->val << std::endl;

    return 0;
}
