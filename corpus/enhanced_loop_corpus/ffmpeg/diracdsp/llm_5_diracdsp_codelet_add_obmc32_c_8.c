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
    for (x = 0; x < 32; x += 2) {
        int skip_first = (obmc_weight[x] == 0);
        int skip_second = (obmc_weight[x + 1] == 0);
        if (!skip_first) {
            dst[x] += src[x] * obmc_weight[x];
        }
        if (!skip_second) {
            dst[x + 1] += src[x + 1] * obmc_weight[x + 1];
        }
    }
}
