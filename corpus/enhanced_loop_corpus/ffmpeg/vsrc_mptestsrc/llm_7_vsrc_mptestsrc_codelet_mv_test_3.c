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
    int base_offset;
    for (y = 0; y < 16 * 16; y++) {
        if (y & 16)
            continue;
        base_offset = off * 8 / (y / 32 + 1);
        for (x = 0; x < 16 * 16; x++) {
            dst[x + y * dst_linesize] = (x + base_offset) ^ dst[x + y * dst_linesize];
            base_offset = (base_offset + 1) % 256;
        }
    }
}
