#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *obmc_weight;
extern int stride;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = x; i < stride; i++) {
        obmc_weight[i] = (uint8_t)((i * i + 3 * i + 1) % 256);
    }
}
