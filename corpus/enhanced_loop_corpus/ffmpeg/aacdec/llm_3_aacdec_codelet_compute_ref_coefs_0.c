#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern  LPC_TYPE *autoc;
extern int max_order;
extern int i;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via offset array)
    // Uses precomputed indices accessed indirectly to demonstrate non-sequential pattern
    int indices[32];
    int i;
    for (i = 0; i < max_order; i++) {
        indices[i] = i + 1;  // Store intended offset
    }
    for (i = 0; i < max_order; i++) {
        int idx = indices[i];         // Indirect access through index array
        gen0[i] = autoc[idx];
        gen1[i] = autoc[idx];
    }
}
