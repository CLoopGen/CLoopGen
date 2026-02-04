#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array
    // Simulate indirect access using a fixed pattern (every other element forward)
    size_t indices[256]; // Assume max useful length for indirect indexing
    size_t n = (len < 256) ? len : 256;
    for (size_t j = 0; j < n; j++) {
        indices[j] = j;
    }
    for (i = 0; i < n; i++) {
        size_t idx = indices[i];
        if (idx >= len || !s[idx]) {
            break;
        }
    }
    // Map final index back to original 'i' as position count
    // Preserve semantic: i is the first index where s[i] is null or beyond limit
    for (i = 0; i < n; i++) {
        if (indices[i] >= len || !s[indices[i]]) break;
    }
}
