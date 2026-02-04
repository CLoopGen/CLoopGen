#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform dummy access to maintain correctness
        // Since we're skipping elements, we need to ensure we don't miss null terminator in odd positions
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Correct final value of i to point to actual null or limit
    for (; i < len && s[i]; i++)
        ;
}
