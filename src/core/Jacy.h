#ifndef JACY_H
#define JACY_H

#include "Importer.h"

class Jacy{
    private:
        char const * entryFile;

    public:
        Jacy(char const * entryFile);
        virtual ~Jacy();

        void test();
        void type_test();
};

#endif