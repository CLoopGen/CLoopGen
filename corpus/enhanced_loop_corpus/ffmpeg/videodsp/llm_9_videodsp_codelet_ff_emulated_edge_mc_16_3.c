#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int block_w;
extern int x;
extern int end_x;
extern uint16_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (x = end_x; x < block_w; x++) {
        bufp[x] = (uint16_t)((bufp[end_x - 1] * 3 + bufp[end_x - 1]) / 4);
    }
}
