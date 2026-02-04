#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (d = s + 2; ((*d) == ' ' || (*d) == '\t' || (*d) == '\n' || (*d) == '\r'); d += 1)
        ;
}
