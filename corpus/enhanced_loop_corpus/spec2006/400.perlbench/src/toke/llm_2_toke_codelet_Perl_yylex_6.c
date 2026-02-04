#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second character)
    for (t = s; ((*t) == ' ' || (*t) == '\t' || *t == '\r'); t += 2) {
        if (*(t + 1) != ' ' && *(t + 1) != '\t' && *(t + 1) != '\r') {
            t++;
            break;
        }
    }
}
