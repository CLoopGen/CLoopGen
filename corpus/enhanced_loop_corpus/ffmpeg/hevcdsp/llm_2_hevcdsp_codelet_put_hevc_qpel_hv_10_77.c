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
        const uint16_t *s = (const uint16_t*)((const char*)src + offset);
        tmp[x] = (f[0] * s[-3] + f[1] * s[-2] + f[2] * s[-1] + f[3] * s[0] +
                  f[4] * s[1] + f[5] * s[2] + f[6] * s[3] + f[7] * s[4]) >> 2;
    }
    src += srcstride;
    tmp += 64;
}
}
