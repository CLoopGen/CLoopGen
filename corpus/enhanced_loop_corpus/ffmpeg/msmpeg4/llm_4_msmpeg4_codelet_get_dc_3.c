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
        if (y % 2 == 0) {
            for (x = 0; x < block_size; x++) {
                sum += src[x + y * stride];
            }
        } else {
            for (x = block_size - 1; x >= 0; x--) {
                sum += src[x + y * stride];
            }
        }
    }
}
