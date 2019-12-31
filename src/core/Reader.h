#ifndef READER_H
#define READER_H

#include <stdlib.h>
#include <iostream>
#include <cstring>

using std::string;
using std::to_string;
using std::cerr;

class Reader{
    private:
        char const * inputText;
        char current;
        int index;
        int lastIndex;

        int size;

        int line;
        int cursor;

    public:
        Reader();
        Reader(char const * inputText);
        virtual ~Reader();

        char peek();
        char advance();
        bool end();

        int getSize(){
            return size;
        }

        // Show error with line and cursor position
        // TODO: Add start benchmark
        void error(string message, bool fatal = 0){
            cerr << "ERROR Occured\n";
            cerr << "[INPUT]["+ to_string(line) +":"+ to_string(cursor) +"]"+ message << message << '\n';

            if(fatal) exit(EXIT_FAILURE);
        }
};

#endif