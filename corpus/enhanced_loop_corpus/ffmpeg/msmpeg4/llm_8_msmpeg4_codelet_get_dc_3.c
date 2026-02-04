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
for (y = 0; y < block_size; y += 2) {
    int x;
    for (x = 0; x < block_size; x += 2) {
        sum += src[x + y * stride];
        sum += src[(x+1) + y * stride];
        sum += src[x + (y+1) * stride];
        sum += src[(x+1) + (y+1) * stride];
    }
}
}
