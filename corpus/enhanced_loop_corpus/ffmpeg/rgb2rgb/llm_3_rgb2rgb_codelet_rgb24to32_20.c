#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed input traversal (indirect-like pattern)
    int stride = 3;
    int num_elements = src_size / 3;
    for (i = 0; i < num_elements; i++) {
        int reversed_idx = src_size - 3 * i - 3; // Reverse the chunk order
        dst[4 * i + 0] = src[reversed_idx + 2];
        dst[4 * i + 1] = src[reversed_idx + 1];
        dst[4 * i + 2] = src[reversed_idx + 0];
        dst[4 * i + 3] = 255;
    }
}
