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
for (i = 0; i < 16; i++) {
    for (j = 0; j < 16; j += 8) {
        register uint32_t x = *(uint32_t *)pix;
        s += sq[x & 255];
        s += sq[(x >> 8) & 255];
        s += sq[(x >> 16) & 255];
        s += sq[(x >> 24) & 255];
        x = *(uint32_t *)(pix + 4);
        s += sq[x & 255];
        s += sq[(x >> 8) & 255];
        s += sq[(x >> 16) & 255];
        s += sq[(x >> 24) & 255];
        pix += 8;
    }
    pix += line_size - 16;
}

}
