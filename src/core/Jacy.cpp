#include "Jacy.h"

using namespace std;

Jacy::Jacy(char const * entryFile){
    this->entryFile = entryFile;
};
Jacy::~Jacy(){};

void Jacy::test(){
    Importer importer;
    importer.import(entryFile);
}

void Jacy::type_test(){
    cout << "Run type test with file spike/lexer/types.jc" << endl;
    Importer importer;
    importer.import("spike/lexer/types.jc");
}