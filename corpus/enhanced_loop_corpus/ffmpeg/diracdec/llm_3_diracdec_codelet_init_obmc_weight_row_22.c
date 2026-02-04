#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *obmc_weight;
extern int stride;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++)
        for (; x < stride; x++)
            obmc_weight[x] = 0;
}
