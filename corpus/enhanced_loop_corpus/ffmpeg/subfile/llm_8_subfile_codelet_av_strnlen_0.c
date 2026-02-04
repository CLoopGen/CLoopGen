#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t step = 1;
    for (; i < len && s[i]; i += step) {
        // Increase arithmetic operations per iteration
        step = (s[i + 1] ? 1 : 1); // Dummy conditional to increase computation
        if (i + 2 < len && s[i+1] && s[i+2]) {
            i++; // Slight trip count reduction by occasionally skipping ahead
        }
    }
}
