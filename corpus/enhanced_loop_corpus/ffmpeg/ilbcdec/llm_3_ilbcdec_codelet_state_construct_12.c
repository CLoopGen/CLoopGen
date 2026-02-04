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
    // Variant 2: Strided memory access on ilbc_state with step size 2 (backward scanning with stride)
    int16_t *local_tmp1 = tmp1;
    int16_t *local_tmp2 = tmp2;
    int stride = 2;
    for (k = 0; k < len; k += stride) {
        if ((local_tmp2 - &ilbc_state[0]) >= 0) {
            (*local_tmp1) = (int16_t)((((int32_t)(maxVal * (*local_tmp2))) + 262144) >> 19);
            local_tmp1++;
            local_tmp2--;
        }
        // Handle potential second element in stride if within bounds
        if (k + 1 < len && (local_tmp2 - &ilbc_state[0]) >= 0) {
            (*local_tmp1) = (int16_t)((((int32_t)(maxVal * (*local_tmp2))) + 262144) >> 19);
            local_tmp1++;
            local_tmp2--;
        }
    }
}
