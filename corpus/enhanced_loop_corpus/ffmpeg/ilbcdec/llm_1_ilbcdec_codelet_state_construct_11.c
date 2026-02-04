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
    for (k = 0; k < len; k += 2) {
        if (k + 1 < len) {
            // Unrolled to simulate reduced effective nesting depth via flattened logic
            (*tmp1) = (int16_t)((((int32_t)(((int16_t)(maxVal)) * ((int16_t)(ilbc_state[(*tmp2)])))) + 2097152) >> 22);
            tmp1++;
            tmp2--;

            (*tmp1) = (int16_t)((((int32_t)(((int16_t)(maxVal)) * ((int16_t)(ilbc_state[(*tmp2)])))) + 2097152) >> 22);
            tmp1++;
            tmp2--;
        } else {
            // Handle odd-sized len safely
            (*tmp1) = (int16_t)((((int32_t)(((int16_t)(maxVal)) * ((int16_t)(ilbc_state[(*tmp2)])))) + 2097152) >> 22);
            tmp1++;
            tmp2--;
        }
    }
}
