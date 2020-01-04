#ifndef IMPORTER_H
#define IMPORTER_H

#include <iostream>

using std::string;
using std::ifstream;

class Importer{
    public:
        Importer();
        virtual ~Importer();

        void import(string filepath);
};

#endif