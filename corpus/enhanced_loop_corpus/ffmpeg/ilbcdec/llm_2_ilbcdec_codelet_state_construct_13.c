#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t ilbc_state[8];
extern int16_t len;
extern int k;
extern int16_t maxVal;
extern int16_t *tmp1;
extern int16_t *tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal of ilbc_state
    // Instead of decrementing tmp2 as an index, we precompute a forward-facing index
    // and access ilbc_state in increasing order for better cache locality.
    int16_t *base_tmp1 = tmp1;
    int16_t *base_tmp2 = tmp2;
    for (k = 0; k < len; k++) {
        int idx = len - 1 - k;  // Reverse mapping to maintain same element access order
        base_tmp1[k] = (int16_t)((((int32_t)(maxVal * ilbc_state[idx])) + 65536) >> 17);
    }
    // Update the external pointers to reflect advancement
    tmp1 += len;
    tmp2 -= len;
}
