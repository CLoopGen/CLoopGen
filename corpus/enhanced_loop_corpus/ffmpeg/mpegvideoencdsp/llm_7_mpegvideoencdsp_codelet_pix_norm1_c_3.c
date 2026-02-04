#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix;
extern int line_size;
extern int s;
extern int i;
extern int j;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_s = s;
    for (i = 0; i < 16; i++) {
        uint32_t row_accum = 0;
        for (j = 0; j < 16; j += 8) {
            register uint32_t x = *(uint32_t *)pix;
            row_accum += sq[x & 255];
            row_accum += sq[(x >> 8) & 255];
            row_accum += sq[(x >> 16) & 255];
            row_accum += sq[(x >> 24) & 255];
            x = *(uint32_t *)(pix + 4);
            row_accum += sq[x & 255];
            row_accum += sq[(x >> 8) & 255];
            row_accum += sq[(x >> 16) & 255];
            row_accum += sq[(x >> 24) & 255];
            pix += 8;
        }
        local_s += row_accum;
        pix += line_size - 16;
    }
    s = local_s;
}
