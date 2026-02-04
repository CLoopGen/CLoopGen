#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride to simulate sparse traversal
    int start = (i0 >> 1);
    int end = (i1 >> 1);
    int stride = 2;
    for (i = start; i < end; i += stride) {
        int64_t sum = (int64_t)p[2 * i] + p[2 * i + 2];
        p[2 * i + 1] += (103949LL * sum + (1 << 15)) >> 16;
        // Process next in-stride element if within bounds
        if (i + 1 < end) {
            int64_t sum_next = (int64_t)p[2*(i+1)] + p[2*(i+1)+2];
            p[2*(i+1)+1] += (103949LL * sum_next + (1 << 15)) >> 16;
        }
    }
}
