#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic with an offset array (simulated small stride pattern)
    size_t j;
    for (j = 0; j < len; j++) {
        i = j; // Map index indirectly
        if (!s[i]) break;
    }
    i = j; // Ensure 'i' reflects the final position as in original
}
