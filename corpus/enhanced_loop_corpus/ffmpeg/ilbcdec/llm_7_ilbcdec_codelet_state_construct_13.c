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
    int16_t *t1 = tmp1;
    int16_t *t2 = tmp2;
    int16_t local_val = 0;
    for (k = 0; k < len; k++) {
        int32_t scaled = ((int32_t)(maxVal * ilbc_state[t2[-k]])) + 65536;
        local_val = (int16_t)(scaled >> 17);
        t1[k] = local_val;
    }
    tmp1 = t1 + len;
    tmp2 = t2 - len;
}
