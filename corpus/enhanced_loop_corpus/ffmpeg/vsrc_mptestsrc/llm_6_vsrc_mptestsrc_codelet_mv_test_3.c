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
    uint8_t temp;
    for (y = 0; y < 16 * 16; y++) {
        if (y & 16)
            continue;
        temp = off * 8;
        for (x = 0; x < 16 * 16; x++) {
            int index = x + y * dst_linesize;
            int denom = (y / 32 + 1);
            dst[index] = (x + temp / denom) & 0xFF;
        }
    }
}
