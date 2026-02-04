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
    // Variant 2: Strided column-major memory access (transpose-like traversal)
    // Access is now stride-1 apart, increasing temporal reuse of cache lines across iterations
    for (int x = 0; x < block_size; x++) {
        for (y = 0; y < block_size; y++) {
            sum += src[x + y * stride];
        }
    }
}
