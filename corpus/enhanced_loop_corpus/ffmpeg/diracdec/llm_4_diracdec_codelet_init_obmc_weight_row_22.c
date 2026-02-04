#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *obmc_weight;
extern int stride;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then offset)
    for (int step = 2; step > 0; step--) {
        for (int i = x + (step == 2 ? 0 : 1); i < stride; i += 2)
            obmc_weight[i] = 0;
    }
}
