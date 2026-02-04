#include <stdio.h>

#include <inttypes.h>

extern char *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i = 0;
    char c;
    for (; (c = w[i]) && (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'); i++)
        ;
    w += i;
}
