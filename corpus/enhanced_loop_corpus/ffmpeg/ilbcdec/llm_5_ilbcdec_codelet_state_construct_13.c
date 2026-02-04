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
        int16_t index = (*tmp2);
        if (index >= 0 && index < 8) {
            (*tmp1) = (int16_t)((((int32_t)(maxVal * ilbc_state[index])) + 65536) >> 17);
        } else {
            (*tmp1) = maxVal;
        }
        tmp1++;
        tmp2--;
    }
}
