#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern  uint32_t *qmul;
extern int level[16];
extern int total_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access pattern - process every second coefficient in reverse order using a calculated stride
    int16_t *block_ptr = (int16_t *)block;
    int stride = 2;
    int start = total_coeff - (total_coeff % stride); // Align start to nearest multiple of stride
    for (int j = start - stride; j >= i; j -= stride) {
        uint8_t index = *(--scantable);
        block_ptr[index] = ((int)(level[j] * qmul[index] + 32)) >> 6;
        if (j - stride < i) break;
        // Simulate continued scan table movement for strided elements
        scantable--;
        j--; // Adjust loop counter to match two-step decrement
    }
    // Handle remaining coefficients if total_coeff is not divisible by stride
    for (; i < total_coeff; i++) {
        scantable--;
        block_ptr[*scantable] = ((int)(level[i] * qmul[*scantable] + 32)) >> 6;
    }
}
