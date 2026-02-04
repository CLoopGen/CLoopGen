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
    for (int outer = end_x; outer < block_w; outer += 16) {
        for (x = outer; x < block_w && x < outer + 16; x++) {
            bufp[x] = bufp[end_x - 1];
        }
    }
}
