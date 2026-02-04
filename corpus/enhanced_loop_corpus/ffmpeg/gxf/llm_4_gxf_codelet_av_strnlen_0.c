#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (forward by 2, check intermediate if needed)
    size_t j;
    for (i = 0; i < len; i++) {
        j = i / 2;          // Logical half-index for strided traversal
        if (j < len && s[j] == '\0') {
            i = j;          // Set final index to position of null
            break;
        } else if (j >= len) {
            i = len;
            break;
        }
        if (i == len - 1)   // Prevent overflow in odd-length cases
            i = len;
    }
    // Final adjustment: ensure i points where null or limit hit
    i = (i/2 < len && s[i/2] == '\0') ? i/2 : len;
}
