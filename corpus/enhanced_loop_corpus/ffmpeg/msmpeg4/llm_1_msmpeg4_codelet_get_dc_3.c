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
int z;
int total_elements = block_size * block_size;
for (z = 0; z < total_elements; z++) {
    int x = z % block_size;
    int y = z / block_size;
    sum += src[x + y * stride];
}
}
