#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_filter[5];
    for (int i = 0; i < 5; i++) {
        local_filter[i] = filter[i];
    }
    for (y = 0; y < h + 4 - 1; y++) {
        uint8_t temp_accum[16] = {0};
        for (x = 0; x < 16; x++) {
            int index = x + 0 * 1;
            int val = local_filter[2] * src[index];
            val -= local_filter[1] * src[index - 1];
            val += local_filter[3] * src[index + 1];
            val -= local_filter[4] * src[index + 2];
            temp_accum[x] = cm[(val + 64) >> 7];
        }
        for (x = 0; x < 16; x++) {
            tmp[x] = temp_accum[x];
        }
        tmp += 16;
        src += srcstride;
    }
}
