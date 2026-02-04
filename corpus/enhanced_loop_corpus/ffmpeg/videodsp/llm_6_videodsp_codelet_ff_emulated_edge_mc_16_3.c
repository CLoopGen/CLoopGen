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
    int temp = (end_x - 1) >= 0 ? bufp[end_x - 1] : 0;
    for (x = end_x; x < block_w; x++) {
        bufp[x] = temp;
    }
}
