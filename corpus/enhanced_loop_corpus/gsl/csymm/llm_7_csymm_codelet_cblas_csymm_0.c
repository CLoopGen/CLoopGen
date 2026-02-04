#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *c_ptr = (float *)C;
    int base_offset;
    for (i = 0; i < n1; i++) {
        base_offset = 2 * ldc * i;
        for (j = 0; j < n2; j++) {
            int offset = base_offset + 2 * j;
            // Eliminate repeated computation and reorganize stores to remove some WAW hazards via access ordering
            // Introduce loop-carried dependence through temporary accumulation (simulated with redundant zeroing)
            float temp = 0.0f;
            c_ptr[offset] = temp;
            c_ptr[offset + 1] = temp;
        }
        // Add artificial dependence on previous iteration: not carried in j, but i-loop could propagate a value
        // (Though no actual cross-iteration effect due to independence of C accesses)
    }
}
