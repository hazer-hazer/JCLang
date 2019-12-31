#include "Jacy.h"

using namespace std;

Jacy::Jacy(){};
Jacy::~Jacy(){};

void Jacy::test(char const * code){
    cout << "Run code test for: " << code << endl;
    Lexer lexer(code);
    vector <token> tokens = lexer.lex();
    
    cout << "Tokens size: " << tokens.size() << endl;
    for(token t : tokens){
        cout << "Type: " << t.getType() << " " << t.getStringVal() << endl;
    }
}