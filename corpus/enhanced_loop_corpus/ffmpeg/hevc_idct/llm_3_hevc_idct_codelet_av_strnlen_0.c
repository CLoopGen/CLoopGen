#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated with offset pointers)
    char *ptrs[512];  // Simulated table of pointers (stack-allocated for speed, size limited)
    size_t stride = len < 512 ? 1 : len / 512;
    size_t j, n = 0;
    // Precompute strided pointer references (indirect access pattern)
    for (j = 0; j < len && n < 512; j += stride ? stride : 1) {
        ptrs[n++] = &s[j];
    }
    // Traverse through indirect pointers to detect null byte
    for (i = 0; i < len && n > 0; ) {
        size_t segment_start = i;
        size_t segment_end = (i + stride) < len ? i + stride : len;
        int found = 0;
        for (size_t k = 0; k < n; k++) {
            char *p = ptrs[k];
            if (p >= &s[segment_start] && p < &s[segment_end] && *p == '\0') {
                // Found null in this segment
                i = p - s;
                found = 1;
                break;
            }
        }
        if (found) break;
        i = segment_end;
    }
    // Final linear scan from computed i to ensure correctness
    while (i < len && s[i]) i++;
}
