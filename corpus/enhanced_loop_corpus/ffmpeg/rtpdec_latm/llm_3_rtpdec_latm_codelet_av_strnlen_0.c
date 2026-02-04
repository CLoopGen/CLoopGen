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
    size_t indices[1024]; // Local index buffer for indirect access (practical for small known sizes)
    size_t max_indirect = len < 1024 ? len : 1024;
    for (i = 0; i < max_indirect; i++) {
        indices[i] = i; // Identity mapping for indirect access
    }
    i = 0;
    for (size_t j = 0; j < max_indirect; j++) {
        size_t idx = indices[j];
        if (idx >= len || !s[idx]) {
            i = idx;
            break;
        }
        i = idx + 1; // Update final 'i' to correct position
    }
}
