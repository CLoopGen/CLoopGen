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
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x++) {
        int offset = x;
        const int8_t *f = filter;
        const uint16_t *s = (const uint16_t*)((const char*)src - 3 * srcstride);
        tmp[x] = (
            f[0] * s[offset + 0 * srcstride] +
            f[1] * s[offset + 1 * srcstride] +
            f[2] * s[offset + 2 * srcstride] +
            f[3] * s[offset + 3 * srcstride] +
            f[4] * s[offset + 4 * srcstride] +
            f[5] * s[offset + 5 * srcstride] +
            f[6] * s[offset + 6 * srcstride] +
            f[7] * s[offset + 7 * srcstride]
        ) >> 2;
    }
    src += srcstride;
    tmp += 64;
}
}
