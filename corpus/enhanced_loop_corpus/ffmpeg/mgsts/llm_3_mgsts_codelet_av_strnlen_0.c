#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated stride)
    size_t indices[256]; // Local index buffer for indirect access pattern
    size_t max_i = (len < 256) ? len : 256;
    for (size_t j = 0; j < max_i; j++) {
        indices[j] = j; // Direct mapping for simplicity, could be shuffled or strided
    }
    for (i = 0; i < max_i; i++) {
        size_t idx = indices[i];
        if (idx >= len || !s[idx]) {
            i = idx;
            break;
        }
    }
}
