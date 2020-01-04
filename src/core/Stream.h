#ifndef STREAM_H
#define STREAM_H

#include <stdlib.h>
#include <iostream>
#include <cstring>

using std::string;
using std::to_string;
using std::cerr;
using std::endl;

class Stream{
    private:
        char const * inputText;
        char current;
        int index;
        int lastIndex;

        int size;

        int line;
        int cursor;

    public:
        Stream();
        Stream(char const * inputText);
        virtual ~Stream();

        char peek();
        char advance();
        bool end();

        int getSize(){
            return size;
        }

        // Show error with line and cursor position
        // TODO: Add start benchmark
        void error(string message, bool fatal = 0){
            cerr << "ERROR Occured" << endl;
            cerr << "[INPUT]["+ to_string(line) +":"+ to_string(cursor) +"]"+ message << message << endl;

            if(fatal) exit(EXIT_FAILURE);
        }
};

#endif