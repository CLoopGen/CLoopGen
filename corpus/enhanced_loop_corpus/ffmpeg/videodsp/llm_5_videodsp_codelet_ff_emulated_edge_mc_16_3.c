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
    x = end_x;
    if (x < block_w) {
        bufp[x] = bufp[end_x - 1];
        x++;
        for (; x < block_w; x++) {
            bufp[x] = bufp[end_x - 1];
        }
    }
}
