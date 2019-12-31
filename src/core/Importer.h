#ifndef IMPORTER_H
#define IMPORTER_H

using std::string;

class Importer{
    public:
        Importer();
        virtual ~Importer();

        void import(string filepath);
    private:
}

#endif