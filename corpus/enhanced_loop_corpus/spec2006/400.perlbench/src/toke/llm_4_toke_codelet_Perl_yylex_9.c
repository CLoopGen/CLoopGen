#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (d = s + 1; ((*d) == ' ' || (*d) == '\t'); d++) {
        if (!(*d)) break;
    }
}
