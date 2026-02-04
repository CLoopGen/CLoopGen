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
    int offset = len - 1;
    for (k = 0; k < len; k++) {
        int16_t index = *(tmp2 - k); 
        int32_t product = (int32_t)(local_maxVal * ilbc_state[index]);
        *(tmp1 + k) = (int16_t)((product + 2097152) >> 22);
    }
}
