#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 64; y++) {
    int local_x = y & 7;
    int local_y = y >> 3;
    dst[local_x] = (src[(8) + 7 - local_y] * (8 - local_x) + src[(8 + 8 + 1) + local_x] * local_x + 4) >> 3;
    if ((local_x == 7)) dst += stride;
}
}
