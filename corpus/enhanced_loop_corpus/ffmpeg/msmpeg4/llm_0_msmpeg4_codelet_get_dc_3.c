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
int y;
for (y = 0; y < block_size * block_size; y++) {
    sum += src[y % block_size + (y / block_size) * stride];
}
}
