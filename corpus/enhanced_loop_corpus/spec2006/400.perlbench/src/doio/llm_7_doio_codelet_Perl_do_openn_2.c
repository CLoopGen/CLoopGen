#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i = 0;
    char current;
    for (; ((current = *(type + i)) == ' ' || current == '\t' || current == '\n' || current == '\r' || current == '\f'); i++)
        ;
    type += i;
}
