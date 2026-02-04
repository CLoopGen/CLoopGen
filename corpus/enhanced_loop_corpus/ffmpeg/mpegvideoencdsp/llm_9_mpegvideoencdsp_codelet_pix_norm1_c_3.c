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
for (i = 0; i < 32; i++) {
    for (j = 0; j < 8; j += 8) {
        register uint32_t x1 = *(uint32_t *)pix;
        register uint32_t x2 = *(uint32_t *)(pix + 4);
        register uint32_t x3 = *(uint32_t *)(pix + line_size);
        register uint32_t x4 = *(uint32_t *)(pix + line_size + 4);
        s += sq[x1 & 255] + sq[(x1 >> 8) & 255] + sq[(x1 >> 16) & 255] + sq[(x1 >> 24) & 255];
        s += sq[x2 & 255] + sq[(x2 >> 8) & 255] + sq[(x2 >> 16) & 255] + sq[(x2 >> 24) & 255];
        s += sq[x3 & 255] + sq[(x3 >> 8) & 255] + sq[(x3 >> 16) & 255] + sq[(x3 >> 24) & 255];
        s += sq[x4 & 255] + sq[(x4 >> 8) & 255] + sq[(x4 >> 16) & 255] + sq[(x4 >> 24) & 255];
        pix += 8;
    }
    pix += 2 * (line_size - 8);
}
}
