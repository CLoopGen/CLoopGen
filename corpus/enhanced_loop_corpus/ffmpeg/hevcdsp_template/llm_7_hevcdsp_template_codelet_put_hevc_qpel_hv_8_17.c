#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int8_t f0 = filter[0], f1 = filter[1], f2 = filter[2], f3 = filter[3];
int8_t f4 = filter[4], f5 = filter[5], f6 = filter[6], f7 = filter[7];
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x += 4) {
        int16_t sum0 = f0 * src[x - 3] + f1 * src[x - 2] + f2 * src[x - 1] + f3 * src[x] +
                       f4 * src[x + 1] + f5 * src[x + 2] + f6 * src[x + 3] + f7 * src[x + 4];
        int16_t sum1 = f0 * src[x - 2] + f1 * src[x - 1] + f2 * src[x    ] + f3 * src[x + 1] +
                       f4 * src[x + 2] + f5 * src[x + 3] + f6 * src[x + 4] + f7 * src[x + 5];
        int16_t sum2 = f0 * src[x - 1] + f1 * src[x    ] + f2 * src[x + 1] + f3 * src[x + 2] +
                       f4 * src[x + 3] + f5 * src[x + 4] + f6 * src[x + 5] + f7 * src[x + 6];
        int16_t sum3 = f0 * src[x    ] + f1 * src[x + 1] + f2 * src[x + 2] + f3 * src[x + 3] +
                       f4 * src[x + 4] + f5 * src[x + 5] + f6 * src[x + 6] + f7 * src[x + 7];

        tmp[x]     = sum0 >> 0;
        tmp[x + 1] = sum1 >> 0;
        tmp[x + 2] = sum2 >> 0;
        tmp[x + 3] = sum3 >> 0;
    }
    src += srcstride;
    tmp += 64;
}
}
