#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *obmc_weight;
extern int stride;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (x < stride) {
        do {
            obmc_weight[x] = 0;
            x++;
        } while (x < stride);
    }
}
