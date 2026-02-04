#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char val = '\1';
    for (i = 0; i < len && val; i++) {
        val = s[i]; // Move s[i] load into loop body; introduce loop-carried dependency via 'val'
        // RAW dependency: s[i] -> val, then val used in next iteration condition
        // This creates a sequential data dependency that prevents certain vectorizations
    }
    if (!val) i--; // Adjust i to point to the null character, preserving original behavior
}
