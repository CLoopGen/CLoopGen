#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *decoded;
extern  int coeffs[32];
extern int order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Precompute an indirect index mapping for shuffled access pattern
    int indices[32];
    for (int k = 0; k < order; k++) {
        indices[k] = (k * 7) % order;  // pseudo-random permutation via linear congruential map
    }
    for (i = order; i < len; i++, decoded++) {
        int32_t p = 0;
        // Modified memory access: Indirect (gather) access using permuted indices
        for (j = 0; j < order; j++) {
            int mapped_idx = indices[j];
            p += coeffs[mapped_idx] * (uint32_t)decoded[mapped_idx];
        }
        decoded[0] += p >> qlevel;  // Write result back to current base (adjusted location)
    }
}
