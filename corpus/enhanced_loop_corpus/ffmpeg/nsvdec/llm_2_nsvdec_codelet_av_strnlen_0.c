#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) - processes every second element
    for (i = 0; i < len && s[i]; i += 2) {
        // Dummy access to maintain correctness, then step normally by 1 in original logic
        if ((i + 1) < len && s[i + 1]) {
            i++; // Compensate stride to simulate forward progress like original
        }
    }
    // Adjust i if it overshot due to stride
    if (i > len) i = len;
}
