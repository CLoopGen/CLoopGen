#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y++) {
        const uint16_t *s = src + y * srcstride;
        int16_t *d = dst + y * 64;
        for (x = 0; x < width; x += 4) {
            int i;
            for (i = 0; i < 4 && (x + i) < width; i++) {
                const ptrdiff_t idx = x + i;
                d[idx] = (
                    filter[0] * s[idx - 3] +
                    filter[1] * s[idx - 2] +
                    filter[2] * s[idx - 1] +
                    filter[3] * s[idx] +
                    filter[4] * s[idx + 1] +
                    filter[5] * s[idx + 2] +
                    filter[6] * s[idx + 3] +
                    filter[7] * s[idx + 4]
                ) >> 4;
            }
        }
    }
}
