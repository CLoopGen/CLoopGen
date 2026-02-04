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
for (y = 0; y < h + 4 - 1; y++) {
    uint8_t temp_val;
    for (x = 0; x < 16; x++) {
        temp_val = (filter[2] * src[x + 0] - filter[1] * src[x - 1] + filter[0] * src[x - 2] +
                    filter[3] * src[x + 1] - filter[4] * src[x + 2] + filter[5] * src[x + 3] + 64) >> 7;
        tmp[x] = cm[temp_val];
    }
    tmp += 16;
    src += srcstride;
}
}
