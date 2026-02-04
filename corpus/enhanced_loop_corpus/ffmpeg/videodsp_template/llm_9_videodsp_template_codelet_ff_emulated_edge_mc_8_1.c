#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int block_w;
extern int x;
extern int end_x;
extern uint8_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step;
    for (x = end_x, step = 0; x < block_w; x++, step++) {
        if (step % 2 == 0) {
            bufp[x] = bufp[end_x - 1];
        } else {
            bufp[x] = (bufp[end_x - 1] + bufp[end_x - 1]) >> 1;
        }
    }
}
