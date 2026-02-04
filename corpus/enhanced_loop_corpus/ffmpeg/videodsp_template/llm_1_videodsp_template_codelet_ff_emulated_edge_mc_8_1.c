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
    if (end_x < block_w) {
        for (int i = end_x; i < block_w; i++) {
            bufp[i] = bufp[end_x - 1];
        }
    }
}
