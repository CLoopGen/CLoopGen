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
        // Access current element to maintain side effect
        if (s[i]) {
            // Continue scanning, but step by 2
            if (i + 1 < len && s[i + 1]) {
                // Dummy check to simulate forward progress
            } else {
                break;
            }
        }
    }
    // Fix up index: ensure `i` points to the correct termination position
    for (; i < len && s[i]; i++)
        ;
}
