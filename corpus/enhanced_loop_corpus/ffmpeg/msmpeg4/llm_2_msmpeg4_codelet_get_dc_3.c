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
    // Variant 1: Consecutive memory access by precomputing row base pointers
    // This improves spatial locality by accessing memory in a more sequential pattern
    for (y = 0; y < block_size; y++) {
        uint8_t *row = &src[y * stride];
        for (int x = 0; x < block_size; x++) {
            sum += row[x];
        }
    }
}
