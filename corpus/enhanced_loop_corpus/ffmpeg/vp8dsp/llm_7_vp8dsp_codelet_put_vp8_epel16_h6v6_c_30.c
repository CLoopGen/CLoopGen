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
for (y = 0; y < h + 6 - 1; y++) {
    for (x = 0; x < 16; x++) {
        int index = x - 2;
        int val = (local_filter[2] * src[index + 2] - local_filter[1] * src[index + 1] + 
                   local_filter[0] * src[index + 0] + local_filter[3] * src[index + 3] - 
                   local_filter[4] * src[index + 4] + local_filter[5] * src[index + 5] + 64) >> 7;
        tmp[x] = cm[val];
    }
    tmp += 16;
    src += srcstride;
}
}
