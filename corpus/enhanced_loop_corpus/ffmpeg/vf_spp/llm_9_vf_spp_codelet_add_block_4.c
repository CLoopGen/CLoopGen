#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int linesize;
extern  int16_t block[64];
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    int offset_dst = y * linesize;
    int offset_block = y * 8;
    for (int x = 0; x < 8; x++) {
        if (offset_block + x < 64) {
            dst[x + offset_dst] += block[x + offset_block];
        }
    }
}
}
