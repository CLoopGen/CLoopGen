#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int8_t *f = filter;
for (y = 0; y < height + 3; y++) {
    uint16_t *s = src;
    for (x = 0; x < width; x++) {
        int16_t sum = 0;
        sum += f[0] * s[x - 1];
        sum += f[1] * s[x];
        sum += f[2] * s[x + 1];
        sum += f[3] * s[x + 2];
        tmp[x] = sum >> 4;
    }
    src += srcstride;
    tmp += 64;
}
}
