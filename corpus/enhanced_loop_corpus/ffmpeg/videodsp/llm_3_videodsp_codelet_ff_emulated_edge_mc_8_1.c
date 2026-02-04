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
    // Variant 2: Strided memory access with increasing stride
    int stride = 1;
    for (x = end_x; x < block_w; x += stride) {
        bufp[x] = bufp[end_x - 1];
        stride = (stride << 1) & 7; // Cycle stride values: 1, 2, 4, 0 → 1, 2, 4...
        if (stride == 0) stride = 1;
    }
}
