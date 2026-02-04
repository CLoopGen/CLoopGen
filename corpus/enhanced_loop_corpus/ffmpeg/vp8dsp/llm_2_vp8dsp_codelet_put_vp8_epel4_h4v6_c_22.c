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
for (y = 0; y < h + 6 - 1; y++) {
    uint8_t *src_base = src;
    for (x = 0; x < 4; x++) {
        ptrdiff_t offsets[] = {0, -1, 1, 2};
        int sum = 0;
        sum += filter[2] * src_base[x + offsets[0]];
        sum -= filter[1] * src_base[x + offsets[1]];
        sum += filter[3] * src_base[x + offsets[2]];
        sum -= filter[4] * src_base[x + offsets[3]];
        tmp[x] = cm[(sum + 64) >> 7];
    }
    tmp += 4;
    src += srcstride;
}
}
