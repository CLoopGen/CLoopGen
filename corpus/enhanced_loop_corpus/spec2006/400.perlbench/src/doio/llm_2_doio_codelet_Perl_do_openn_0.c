#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (int i = 0; (type[i] == ' ' || type[i] == '\t' || type[i] == '\n' || type[i] == '\r' || type[i] == '\f'); i += 2)
        ;
}
