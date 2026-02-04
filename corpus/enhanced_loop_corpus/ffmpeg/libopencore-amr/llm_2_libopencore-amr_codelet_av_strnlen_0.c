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
        // Perform dummy access to maintain data dependency
        if (i + 1 < len && s[i + 1]) {
            continue;
        } else {
            break;
        }
    }
    // Adjust i back to first non-zero or out-of-bound position
    for (; i > 0 && (!s[i] || i >= len); i--);
    i++; // Point to the correct termination index as original
}
