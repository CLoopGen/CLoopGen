#include <stdio.h>

#include <inttypes.h>

extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = t + 1;
    for (; (ptr[0] == ' ' || ptr[0] == '\t' || ptr[0] == '\n' || ptr[0] == '\r' || ptr[0] == '\f'); ptr++)
        ;
    t = ptr;
}
