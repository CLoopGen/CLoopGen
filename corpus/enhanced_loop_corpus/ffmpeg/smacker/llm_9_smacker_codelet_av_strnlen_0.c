#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i < 1000; i += 2) {
        if (i + 1 >= len || !s[i + 1]) break;
    }
    // Adjusted step size and trip count limit to reduce effective iterations
    // Also skips every other element, reducing arithmetic comparisons per iteration but changing access pattern
}
