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
for (y = 0; y < 16 * 16; y++) {
    if (y & 16)
        continue;
    uint8_t *row_base = &dst[y * dst_linesize];
    for (x = 0; x < 16 * 16; x += 2) {
        row_base[x] = x + off * 8 / (y / 32 + 1);
        if (x + 1 < 16 * 16)
            row_base[x + 1] = (x + 1) + off * 8 / (y / 32 + 1);
    }
}
}
