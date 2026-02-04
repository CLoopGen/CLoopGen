#include <stdio.h>

#include <inttypes.h>

extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i = 0;
    char c;
    for (; ((c = t[i]) == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'); i++)
        ;
    t += i;
}
