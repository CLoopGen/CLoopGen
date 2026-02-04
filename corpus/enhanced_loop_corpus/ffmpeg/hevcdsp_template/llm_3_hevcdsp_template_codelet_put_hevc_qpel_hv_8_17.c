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
    for (x = 0; x < width; x += 4) {
        // Unroll and access in consecutive groups of 4 to improve spatial locality
        int16_t *t = &tmp[x];
        uint8_t *s = &src[x];
        const int8_t *f = filter;

        t[0] = (f[0] * s[-3] + f[1] * s[-2] + f[2] * s[-1] + f[3] * s[0] + 
                f[4] * s[1] + f[5] * s[2] + f[6] * s[3] + f[7] * s[4]) >> 0;
        if (x + 1 < width)
            t[1] = (f[0] * s[-2] + f[1] * s[-1] + f[2] * s[0] + f[3] * s[1] + 
                    f[4] * s[2] + f[5] * s[3] + f[6] * s[4] + f[7] * s[5]) >> 0;
        if (x + 2 < width)
            t[2] = (f[0] * s[-1] + f[1] * s[0] + f[2] * s[1] + f[3] * s[2] + 
                    f[4] * s[3] + f[5] * s[4] + f[6] * s[5] + f[7] * s[6]) >> 0;
        if (x + 3 < width)
            t[3] = (f[0] * s[0] + f[1] * s[1] + f[2] * s[2] + f[3] * s[3] + 
                    f[4] * s[4] + f[5] * s[5] + f[6] * s[6] + f[7] * s[7]) >> 0;
    }
    src += srcstride;
    tmp += 64;
}
}
