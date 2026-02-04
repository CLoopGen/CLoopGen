#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with forward progress and null check every 2nd step
    size_t step = 2;
    for (i = 0; i < len; i += step) {
        if (!s[i]) break;
        // Ensure we don't miss the null terminator in odd position
        if ((i + 1) < len && !s[i + 1]) {
            i++;
            break;
        }
    }
}
