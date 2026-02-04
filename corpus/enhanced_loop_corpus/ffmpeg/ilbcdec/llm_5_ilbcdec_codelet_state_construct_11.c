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
    for (k = 0; k < len; k++) {
        int16_t product = (int16_t)(maxVal * ilbc_state[(*tmp2)]);
        int32_t shifted_val = ((int32_t)product + 2097152) >> 22;
        if (shifted_val > 0) {
            (*tmp1) = (int16_t)shifted_val;
        } else {
            (*tmp1) = -((int16_t)shifted_val);
        }
        tmp1++;
        tmp2--;
    }
}
