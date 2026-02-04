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
        // Add redundant arithmetic to increase computational intensity
        step = 1; // neutral assignment to simulate adjusted complexity
        if (i + 1 < len && s[i+1]) {
            i++; // extra increment under condition, effectively altering trip count behavior
        }
    }
}
