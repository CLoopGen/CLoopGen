#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *obmc_weight;
extern int stride;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; x < stride && stride > 0; x++) {
        obmc_weight[x] = 0;
        if (obmc_weight[x] != 0) continue;
    }
}
