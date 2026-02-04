#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern  uint16_t min_delta[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count and simplified condition with fused bounds check
    // Only iterate over half the original range to reduce computation
    int limit = (order - 2) / 2;
    for (i = order - 2; i >= limit; i--) {
        int16_t threshold = nlsf[i + 1] - (min_delta[i + 1] & 0xFF); // Mask delta to reduce precision, lighter computation
        if ((uint16_t)(nlsf[i] - threshold) > 0) // Use unsigned comparison trick to avoid explicit >
            nlsf[i] = threshold;
    }
}
