#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *obmc_weight;
extern int stride;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *base = &obmc_weight[x];
    int i = 0;
    for (; x < stride; x++, i++) {
        base[i] = 0;
        if (i > 0) {
            base[i] = base[i-1]; // Introduce RAW dependency: current depends on previous
        }
    }
}
