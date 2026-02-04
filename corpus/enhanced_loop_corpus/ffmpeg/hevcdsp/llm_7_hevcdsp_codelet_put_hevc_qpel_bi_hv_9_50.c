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
        for (x = 0; x < width; x += 2) {
            // Introduce WAW and WAR dependencies by unrolling and reordering computation
            int16_t val0, val1;
            uint16_t *s = src;
            int8_t *f = filter;

            val0 = (f[0] * s[x - 3] + f[1] * s[x - 2] + f[2] * s[x - 1] + f[3] * s[x] +
                    f[4] * s[x + 1] + f[5] * s[x + 2] + f[6] * s[x + 3] + f[7] * s[x + 4]) >> 1;
            val1 = (f[0] * s[x - 2] + f[1] * s[x - 1] + f[2] * s[x    ] + f[3] * s[x + 1] +
                    f[4] * s[x + 2] + f[5] * s[x + 3] + f[6] * s[x + 4] + f[7] * s[x + 5]) >> 1;

            tmp[x]     = val0;
            if (x + 1 < width) {
                tmp[x + 1] = val1;
            }
        }
        src += srcstride;
        tmp += 64;
    }
}
