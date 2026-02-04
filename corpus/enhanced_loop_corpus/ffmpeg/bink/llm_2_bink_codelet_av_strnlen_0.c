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
        // Perform check on current element, then skip the next
        if (i + 1 < len && !s[i + 1]) {
            i++; // Ensure correct termination if next element is null
            break;
        }
    }
    // Correct final position: ensure we stop at first null or boundary
    while (i < len && s[i]) i++;
}
