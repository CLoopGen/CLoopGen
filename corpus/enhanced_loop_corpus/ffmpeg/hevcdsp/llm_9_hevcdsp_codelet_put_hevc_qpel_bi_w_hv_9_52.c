#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 15; y += 2) {
    for (x = 0; x < width; x++) {
        int16_t sum0 = 0, sum1 = 0;
        for (int k = 0; k < 8; k++) {
            sum0 += filter[k] * src[x + k - 3];
            sum1 += filter[k] * src[x + k - 3 + srcstride];
        }
        tmp[x] = sum0 >> 1;
        tmp[x + 64] = sum1 >> 1;
    }
    src += 2 * srcstride;
    tmp += 128;
}
}
