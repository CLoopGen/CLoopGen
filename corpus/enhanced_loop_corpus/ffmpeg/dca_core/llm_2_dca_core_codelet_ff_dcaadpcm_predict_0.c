#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *input;
extern int i;
extern  int16_t *coeff;
extern int64_t pred;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward memory access with reversed array indexing logic
    for (i = 0; i < 4; i++) {
        int idx_input = i; // Access input in forward order: 0,1,2,3
        int idx_coeff = 3 - i; // Reverse coeff access: 3,2,1,0 to preserve original multiplication pairing
        pred += (int64_t)input[idx_input] * coeff[idx_coeff];
    }
}
