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
    if (len > 0) {
        k = 0;
        for (; k < len; ) {
            (*tmp1) = (int16_t)((((int32_t)(((int16_t)(maxVal)) * ((int16_t)(ilbc_state[(*tmp2)])))) + 262144) >> 19);
            tmp1++;
            tmp2--;
            k++;
        }
    }
}
