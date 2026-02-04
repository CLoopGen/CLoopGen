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
    for (int i = end_x; i < block_w; i++) {
        for (int j = 0; j < 1; j++) {
            bufp[i] = bufp[end_x - 1];
        }
    }
}
