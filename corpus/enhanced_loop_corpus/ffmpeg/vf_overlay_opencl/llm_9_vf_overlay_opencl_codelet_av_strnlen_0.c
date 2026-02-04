#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element at a time
    // and increase arithmetic intensity with additional index calculations
    size_t j;
    for (i = 0; (i < len - 3) && s[i]; i += 4) {
        // Process multiple elements in one iteration (loop unrolling effect)
        for (j = 0; j < 4 && (i + j) < len && s[i + j]; j++)
            ;
        if (j < 4) break; // Exit early if null terminator found in chunk
    }
    // Final pass to ensure i is at first null or beyond valid data
    for (; i < len && s[i]; i++)
        ;
}
