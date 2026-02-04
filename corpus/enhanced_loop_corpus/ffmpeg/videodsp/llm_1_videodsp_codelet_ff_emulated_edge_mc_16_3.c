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
    if (end_x < block_w) {
        for (x = end_x; x < block_w; x++) {
            for (int pad = 0; pad < 1; pad++) {
                bufp[x] = bufp[end_x - 1];
            }
        }
    }
}
