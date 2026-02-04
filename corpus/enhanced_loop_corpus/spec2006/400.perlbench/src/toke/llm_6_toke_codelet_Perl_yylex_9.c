#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = s + 1;
    char val;
    for (; (val = *temp) && (val == ' ' || val == '\t'); temp++)
        ;
    d = temp;
}
