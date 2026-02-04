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
        // Increase computational intensity by adding redundant arithmetic
        step = 1; // neutral assignment to simulate variable computation
        if (i + 2 < len && s[i+1] && s[i+2]) {
            i++; // extra increment under condition, effectively increasing average work per iteration
        }
    }
}
