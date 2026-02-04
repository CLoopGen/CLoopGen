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
int8_t local_filter[8];
for (int i = 0; i < 8; i++) {
    local_filter[i] = filter[i];
}
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x++) {
        int16_t acc = 0;
        acc = acc + local_filter[0] * src[x - 3];
        acc = acc + local_filter[1] * src[x - 2];
        acc = acc + local_filter[2] * src[x - 1];
        acc = acc + local_filter[3] * src[x];
        acc = acc + local_filter[4] * src[x + 1];
        acc = acc + local_filter[5] * src[x + 2];
        acc = acc + local_filter[6] * src[x + 3];
        acc = acc + local_filter[7] * src[x + 4];
        tmp[x] = acc >> 4;
    }
    src += srcstride;
    tmp += 64;
}
}
