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
        // Perform check on current element, then skip next
        if (i + 1 < len && s[i + 1]) {
            continue;
        } else {
            break;
        }
    }
    // Adjust i to point to the correct termination position
    if (i >= len || !s[i]) {
        // Already correct
    } else {
        // Resume linear scan from last strided position
        for (; i < len && s[i]; i++)
            ;
    }
}
