#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG n;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern float *c_offset;
extern float *c_offset1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    // Use strided access with unit stride but unrolled by 4 using consecutive indexing
    BLASLONG vector_count = (m >> 2);
    for (BLASLONG k = 0; k < vector_count; k++) {
        float *ptr = c_offset1 + (k << 2); // pointer to each group of 4 elements
        ptr[0] = 0.F;
        ptr[1] = 0.F;
        ptr[2] = 0.F;
        ptr[3] = 0.F;
    }
    // Handle remaining elements with indirect offset via lookup table for memory access pattern variation
    i = (m & 3);
    if (i > 0) {
        // Simulate indirect-like access using a fixed offset map (emulating non-consecutive access)
        BLASLONG remap[] = {0, 1, 3}; // example non-sequential logical order
        float *tail_base = c_offset1 + (vector_count << 2);
        for (BLASLONG k = 0; k < i; k++) {
            tail_base[remap[k]] = 0.F;
        }
    }
}
}
