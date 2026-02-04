#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *cnt;
extern uint32_t maxc;
extern uint32_t totfr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_sum = 0;
    for (i = 0; i < maxc; i++) {
        uint32_t nc = (cnt[i] >> 1) + 1;
        temp_sum += nc;
        cnt[i] = nc;
    }
    totfr += temp_sum;
}
