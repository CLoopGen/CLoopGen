#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint8_t *src;
extern  uint8_t *obmc_weight;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level1 = 0; level1 < 2; level1++) {
        for (int level2 = 0; level2 < 4; level2++) {
            int x = level1 * 4 + level2 * 2;
            if (x >= 8) break;
            dst[x] += src[x] * obmc_weight[x];
            dst[x + 1] += src[x + 1] * obmc_weight[x + 1];
        }
    }
}
