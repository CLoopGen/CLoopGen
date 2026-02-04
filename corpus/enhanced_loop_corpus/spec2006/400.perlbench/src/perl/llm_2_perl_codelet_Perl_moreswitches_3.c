#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd character)
    for (s += 2, e = s; *e; e += 2) {
        if (*(e + 1) == '\0') break;
    }
}
