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
for (y = 0; y < 16 * 8; y++) {
    if (y & 8)
        continue;
    for (x = 0; x < 16 * 8; x++) {
        int temp = y / 16 + 1;
        dst[x + y * dst_linesize] = (x + off * 4) / temp + (x % 3);
    }
}
}
