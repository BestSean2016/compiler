#include "ctp-parser.h"

int main() {
    init_timap();;
    TOKEN token;
    char lchar = ' ';
    char* ptr= gettok(&lchar, "typedef struct test { int a; char b; } test;", &token);

    deinit_timap();
    return (0);
}
