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
for (y = 0; y < 16 * 16; y += 17) {
    for (x = 0; x < 16 * 16; x++)
        dst[x + y * dst_linesize] = x + off * 8 / (y / 32 + 1);
}
}
