#include <stdio.h>

#include <inttypes.h>

extern unsigned char *agenkey;
extern size_t agenkeylen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t found = 0;
    for (i = 0; i < agenkeylen && !found; i++) {
        found = (agenkey[i] != 0);  // Introduce loop-carried dependency via 'found'
        // RAW: each iteration reads 'found' written in same or previous iteration
        // Break condition now embedded in loop guard instead of explicit break
    }
    if (found)
        i--;  // Adjust i to point to the first non-zero element
}
