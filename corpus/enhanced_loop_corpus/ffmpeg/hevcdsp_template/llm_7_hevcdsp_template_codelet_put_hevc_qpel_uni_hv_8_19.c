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
int8_t local_filter[8];
for (int i = 0; i < 8; i++) {
    local_filter[i] = filter[i];
}
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x++) {
        int16_t acc = 0;
        for (int k = 0; k < 8; k++) {
            acc += local_filter[k] * src[x + k - 3];
        }
        tmp[x] = acc >> 8;
    }
    src += srcstride;
    tmp += 64;
}
}
