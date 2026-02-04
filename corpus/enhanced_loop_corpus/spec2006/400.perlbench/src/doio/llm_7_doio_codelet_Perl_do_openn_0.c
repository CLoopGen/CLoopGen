#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char **p = &type;
    for (; ((**p) == ' ' || (**p) == '\t' || (**p) == '\n' || (**p) == '\r' || (**p) == '\f'); )
        (*p)++;
}
