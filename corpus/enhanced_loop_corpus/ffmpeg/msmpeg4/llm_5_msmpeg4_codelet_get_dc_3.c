#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int block_size;
extern int y;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < block_size; y++) {
        int x;
        for (x = 0; x < block_size; x++) {
            if ((x + y) % 2 == 0) {
                sum += src[x + y * stride];
            }
        }
    }
}
