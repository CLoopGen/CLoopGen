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
    // Using a virtual "indirect" sequence: accessing elements in reverse order within segments
    size_t chunk = 4; // Process every 4 elements in reverse
    size_t j = 0;
    for (i = 0; i < len; i++) {
        // Compute indirect index: map linear i to reversed within chunks
        size_t idx = ((i / chunk) * chunk) + (chunk - 1 - (i % chunk));
        if (idx >= len) continue;
        if (!s[idx]) {
            j = idx;
            break;
        }
        j = idx;
    }
    i = j;
}
