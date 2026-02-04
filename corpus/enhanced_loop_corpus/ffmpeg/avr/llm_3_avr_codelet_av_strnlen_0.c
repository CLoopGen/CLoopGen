#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Use a virtual "indirect" sequence: access s[0], s[2], s[4], ... until condition breaks
    size_t idx;
    for (idx = 0; idx < len; idx++) {
        i = idx; // Map logical index to actual index
        if (!s[i]) break;
    }
    // Finalize i to reflect last valid position
    i = idx;
    if (i > len) i = len;
    else if (i > 0 && s[i-1]) i--; // Ensure i points to null or boundary
}
