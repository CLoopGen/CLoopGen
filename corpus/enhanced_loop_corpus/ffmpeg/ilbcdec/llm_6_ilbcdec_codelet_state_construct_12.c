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
    int16_t temp_accum = 0;
    for (k = 0; k < len; k++) {
        int32_t product = ((int32_t)(maxVal)) * ((int16_t)(ilbc_state[(*tmp2)]));
        temp_accum = (int16_t)((product + 262144) >> 19);
        (*tmp1) = temp_accum;
        tmp1++;
        tmp2--;
    }
}
