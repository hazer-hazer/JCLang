#include "Importer.h"
#include "Lexer.h"
// #include "Parser.h"

Importer::Importer(){};
Importer::~Importer(){};

// Read file by filepath and return ???(now only lexing)
void Importer::import(string filepath){
    cout << "Import file: " << filepath << endl;

    ifstream fs(filepath);
    string code;
    for(std::string line; getline( fs, line );)
        code += line + '\n';

    fs.close();

    cout << "Run code test for: \n" << code << endl;

    Lexer lexer(code.c_str());
    vector <token> tokens = lexer.lex();

    for(auto t : tokens){
        cout << "[TOKEN] type: `" << t.getStringType() << "` value: `" << t.getStringVal() << "`\n";
    }
    // Parser parser;
    // Tree tree = parser.parse(tokens);
    // for(auto n : tree)
    //     cout << n->type << endl;
}