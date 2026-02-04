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
    for (x = end_x; x < block_w; x += 2) {
        if (x < block_w) bufp[x] = bufp[end_x - 1];
        if (x + 1 < block_w) bufp[x + 1] = bufp[end_x - 1];
    }
}
