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
    int16_t local_maxVal = maxVal;
    for (k = 0; k < len; k++) {
        int32_t product = ((int32_t)(local_maxVal * ilbc_state[(*tmp2)])) + 65536;
        (*tmp1) = (int16_t)(product >> 17);
        tmp1++;
        tmp2--;
    }
}
