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
    uint8_t prev_val = bufp[end_x - 1];
    for (x = end_x; x < block_w; x++) {
        uint8_t current = bufp[x];
        bufp[x] = prev_val;
        prev_val = current;
    }
}
