#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int width;
extern int x;
extern int mask;
extern int dst_x;
extern int j;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < width; x++) {
    j = (x & 7);
    b = (src[x >> 3] >> (7 - j)) & 1;
    if ((mask << j) & 128) {
        dst[dst_x >> 3] |= b << (7 - (dst_x & 7));
        dst_x++;
    }
}
}
