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
    x = end_x;
    for (; x < block_w && x >= 0; x++) {
        if (end_x - 1 < 0) break;
        bufp[x] = bufp[end_x - 1];
    }
}
