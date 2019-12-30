#ifndef INPUT_H
#define INPUT_H

class Input{
    private:
        char * inputText;
        char current;
        int index;

        int line;
        int cursor;
    public:
        Input(char * inputText);
        ~Input();

        char peek();
        char advance();
};

#endif