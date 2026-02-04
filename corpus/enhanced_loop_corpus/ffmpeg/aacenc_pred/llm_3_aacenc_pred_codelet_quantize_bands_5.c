#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *out;
extern  float *in;
extern  float *scaled;
extern int size;
extern int is_signed;
extern int maxval;
extern  float Q34;
extern  float rounding;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    // Assume we have an externally defined index map: extern int *index_map;
    // For self-containment, we simulate index_map as i itself but accessed indirectly via a shifted view
    // Here, we use a reverse access pattern: process elements from end to beginning (indirect descending order)
    for (i = 0; i < size; i++) {
        int idx = size - 1 - i; // indirect indexing: reverse order
        float qc = scaled[idx] * Q34;
        int tmp = (int)((qc + rounding) > ((float)maxval) ? ((float)maxval) : (qc + rounding));
        if (is_signed && in[idx] < 0.F) {
            tmp = -tmp;
        }
        out[idx] = tmp;
    }
}
