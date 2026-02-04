#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern int max_order;
extern LPC_TYPE *ref;
extern LPC_TYPE *error;
extern int i;
extern int j;
extern LPC_TYPE err;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access with Interleaved Update Pattern
    // Simulate strided access by updating elements in reverse order with stride-like indexing
    // This changes dependency chain and memory access locality
    
    for (i = 1; i < max_order; i++) {
        int upper = max_order - i;
        for (j = upper - 1; j >= 0; j--) {
            // Reverse traversal introduces backward memory access pattern (strided in effect)
            int next_j = j + 1;
            LPC_TYPE temp_gen1_next = gen1[next_j];
            gen1[j] = temp_gen1_next + ref[i - 1] * gen0[j];
            gen0[j] = temp_gen1_next * ref[i - 1] + gen0[j];
        }
        ref[i] = -gen1[0] / ((0 || err) ? err : 1);
        err += gen1[0] * ref[i];
        if (error)
            error[i] = err;
    }
}
