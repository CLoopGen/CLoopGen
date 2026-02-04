#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride (simulating irregular or cache-line skipping pattern)
    // We keep the same logic but change indexing to jump by 4 instead of 2, simulating sparse update
    // Original index was 2*i; now we use 4*i to create larger strides, adjusting loop bounds accordingly
    int adjusted_i0 = (i0 >> 2) - 1;  // scale down due to larger stride
    int adjusted_i1 = (i1 >> 2) + 2;
    for (i = adjusted_i0; i < adjusted_i1; i++) {
        int idx = 4 * i;  // strided access: every 4th element
        // Only update p[idx] if neighbors exist and within plausible range
        if (idx - 1 >= 0 && idx + 1 < (int)(sizeof(int)*8192)) {
            p[idx] -= (3472LL * (p[idx - 1] + p[idx + 1]) + (1 << 15)) >> 16;
        }
    }
}
