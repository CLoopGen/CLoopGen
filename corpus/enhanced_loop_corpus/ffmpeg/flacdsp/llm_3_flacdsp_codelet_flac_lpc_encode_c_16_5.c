#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with arithmetic)
    // Simulate indirect addressing by reversing the access order
    for (i = 0; i < order; i++) {
        int idx = order - 1 - i;  // reverse indexing
        res[idx] = smp[idx];
    }
}
