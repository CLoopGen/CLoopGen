#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    const int offsets[] = {0, -8, -16, 8, 16, 24};
    for (x = 0; x < 8; x++) {
        int sum = 0;
        sum += filter[2] * tmp[x + offsets[0]];
        sum -= filter[1] * tmp[x + offsets[1]];
        sum += filter[0] * tmp[x + offsets[2]];
        sum += filter[3] * tmp[x + offsets[3]];
        sum -= filter[4] * tmp[x + offsets[4]];
        sum += filter[5] * tmp[x + offsets[5]];
        dst[x] = cm[(sum + 64) >> 7];
    }
    dst += dststride;
    tmp += 8;
}
}
