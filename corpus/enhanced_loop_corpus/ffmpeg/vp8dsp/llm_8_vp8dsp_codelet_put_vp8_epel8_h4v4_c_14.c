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
    for (x = 0; x < 8; x++) {
        int sum = 0;
        sum += filter[0] * src[x - 2 * 1];
        sum += filter[1] * src[x - 1 * 1];
        sum += filter[2] * src[x + 0 * 1];
        sum += filter[3] * src[x + 1 * 1];
        sum += filter[4] * src[x + 2 * 1];
        tmp[x] = cm[(sum + 64) >> 7];
    }
    tmp += 8;
    src += srcstride;
}
}
