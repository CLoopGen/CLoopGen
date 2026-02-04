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
    for (y = 0; y < height + 7; y++) {
        for (x = 0; x < width; x += 2) {
            int offset = x - 3;
            int32_t sum1 = 0, sum2 = 0;
            for (int k = 0; k < 8; k++) {
                sum1 += filter[k] * src[offset + x + k];
                if (x + 1 < width)
                    sum2 += filter[k] * src[offset + x + k + 1];
            }
            tmp[x] = (int16_t)(sum1 >> 0);
            if (x + 1 < width)
                tmp[x + 1] = (int16_t)(sum2 >> 0);
        }
        src += srcstride;
        tmp += 64;
    }
}
