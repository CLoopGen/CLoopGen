#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_linesize;
extern int off;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int index;
const int stride = dst_linesize;
for (y = 0; y < 16 * 16; y++) {
    if (y & 16)
        continue;
    for (x = 0; x < 16 * 16; x++) {
        index = x * stride + y;
        dst[index] = x + off * 8 / (y / 32 + 1);
    }
}
}
