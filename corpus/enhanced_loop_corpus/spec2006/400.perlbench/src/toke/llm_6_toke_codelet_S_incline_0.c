#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *p = s;
    char c;
    for (; (c = *p), !(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'); p++)
        ;
    t = p;
}
