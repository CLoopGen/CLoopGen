#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico23_isf_36b[64][7];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased data access density and fused operations
    // Process only 4 iterations instead of 7, but perform two updates per iteration using pointer arithmetic
    for (i = 0; i < 4; i++) {
        float scale = 1.F / (1 << 15);
        int16_t val = dico23_isf_36b[ind[4]][i];
        isf_q[i + 9]       += val * scale;
        if (i < 3) { // Prevent out-of-bounds access
            isf_q[i + 13]  += dico23_isf_36b[ind[4]][6 - i] * scale; // Reverse indexing pattern
        }
    }
}
