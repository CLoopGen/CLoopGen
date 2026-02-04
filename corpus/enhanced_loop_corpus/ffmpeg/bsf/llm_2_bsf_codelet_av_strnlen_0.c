#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds checking
    for (i = 0; i < len && s[i]; i += 2) {
        // Access current element to maintain data dependency
        if (s[i] == '\0') break;
        // Ensure we don't exceed bounds when accessing i+1
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Final adjustment: ensure i points to the first null or end of buffer
    while (i < len && s[i]) i++;
}
