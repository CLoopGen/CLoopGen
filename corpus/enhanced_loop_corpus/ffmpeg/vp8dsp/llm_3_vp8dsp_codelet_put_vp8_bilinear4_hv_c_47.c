#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern int h;
extern int c;
extern int d;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    uint8_t *dst_offset = dst + y * dstride;
    uint8_t *tmp_offset = tmp + y * 4;
    for (x = 0; x < 4; x++)
        dst_offset[x] = (c * tmp_offset[x] + d * tmp_offset[x + 4] + 4) >> 3;
}
}
