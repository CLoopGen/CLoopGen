#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t local_filter[6];
for (int i = 0; i < 6; i++) {
    local_filter[i] = filter[i];
}
for (y = 0; y < h + 4 - 1; y++) {
    int offset = y * srcstride;
    for (x = 0; x < 16; x++) {
        int idx = x + offset;
        int val = (local_filter[2] * src[idx] -
                   local_filter[1] * src[idx - 1] +
                   local_filter[0] * src[idx - 2] +
                   local_filter[3] * src[idx + 1] -
                   local_filter[4] * src[idx + 2] +
                   local_filter[5] * src[idx + 3] + 64) >> 7;
        tmp[y * 16 + x] = cm[val];
    }
}
}
