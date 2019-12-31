#include "core/Jacy.h"

char const * code = "8.1234 + 123 = 123";

int main(int argc, char const *argv[]){
    Jacy jacy;

    jacy.test(code);

    return 0;
}