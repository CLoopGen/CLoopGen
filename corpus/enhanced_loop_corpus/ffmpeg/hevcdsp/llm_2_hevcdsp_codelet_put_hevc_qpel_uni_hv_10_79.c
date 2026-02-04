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
    int8_t *f = filter;
    int16_t *t = tmp;
    uint16_t *s = src;
    for (x = 0; x < width; x++) {
        t[x] = ((int16_t)f[0] * (int16_t)s[x - 3] +
                (int16_t)f[1] * (int16_t)s[x - 2] +
                (int16_t)f[2] * (int16_t)s[x - 1] +
                (int16_t)f[3] * (int16_t)s[x]     +
                (int16_t)f[4] * (int16_t)s[x + 1] +
                (int16_t)f[5] * (int16_t)s[x + 2] +
                (int16_t)f[6] * (int16_t)s[x + 3] +
                (int16_t)f[7] * (int16_t)s[x + 4]) >> 2;
    }
    src += srcstride;
    tmp += 64;
}
}
