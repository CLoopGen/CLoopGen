#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern char *p;
extern char *spec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    // This variant processes every second character, simulating a strided access pattern.
    // It still counts commas but skips every other character for altered memory traversal.
    for (n = 0, p = spec; *p; p += 2) {
        if (*p == ',') {
            n++;
        }
        // Ensure we don't go past the end when accessing p[1]
        if (*(p + 1) == '\0') break;
    }
}
