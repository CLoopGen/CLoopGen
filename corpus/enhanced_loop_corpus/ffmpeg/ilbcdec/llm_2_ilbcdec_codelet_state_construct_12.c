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
    // Variant 1: Consecutive memory access with reversed indexing (forward traversal of ilbc_state)
    int16_t *local_tmp1 = tmp1;
    int16_t *local_tmp2 = tmp2;
    for (k = 0; k < len; k++) {
        (*local_tmp1) = (int16_t)((((int32_t)(maxVal * ilbc_state[k])) + 262144) >> 19);
        local_tmp1++;
    }
}
