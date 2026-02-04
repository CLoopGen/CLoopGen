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
    const uint16_t *s = src;
    int16_t *t = tmp;
    for (x = 0; x < width; x += 4) {
        t[x + 0] = (filter[0] * s[x - 3] + filter[1] * s[x - 2] + filter[2] * s[x - 1] + filter[3] * s[x + 0] + 
                    filter[4] * s[x + 1] + filter[5] * s[x + 2] + filter[6] * s[x + 3] + filter[7] * s[x + 4]) >> 2;
        t[x + 1] = (filter[0] * s[x - 2] + filter[1] * s[x - 1] + filter[2] * s[x + 0] + filter[3] * s[x + 1] + 
                    filter[4] * s[x + 2] + filter[5] * s[x + 3] + filter[6] * s[x + 4] + filter[7] * s[x + 5]) >> 2;
        t[x + 2] = (filter[0] * s[x - 1] + filter[1] * s[x + 0] + filter[2] * s[x + 1] + filter[3] * s[x + 2] + 
                    filter[4] * s[x + 3] + filter[5] * s[x + 4] + filter[6] * s[x + 5] + filter[7] * s[x + 6]) >> 2;
        t[x + 3] = (filter[0] * s[x + 0] + filter[1] * s[x + 1] + filter[2] * s[x + 2] + filter[3] * s[x + 3] + 
                    filter[4] * s[x + 4] + filter[5] * s[x + 5] + filter[6] * s[x + 6] + filter[7] * s[x + 7]) >> 2;
    }
    src += srcstride;
    tmp += 64;
}
}
