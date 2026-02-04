#include <stdio.h>

#include <inttypes.h>

extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char current;
    for (t++; (current = *t, (current == ' ' || current == '\t' || current == '\n' || current == '\r' || current == '\f')); t++)
        ;
}
