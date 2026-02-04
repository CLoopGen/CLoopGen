#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; type[i] != '\0' && (type[i] == ' ' || type[i] == '\t' || type[i] == '\n' || type[i] == '\r' || type[i] == '\f'); i++)
        ;
    type += i;
}
