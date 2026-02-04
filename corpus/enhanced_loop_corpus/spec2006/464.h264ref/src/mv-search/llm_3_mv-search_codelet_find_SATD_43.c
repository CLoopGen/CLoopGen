#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int i;
extern int sad;
extern int block_size_x;
extern int block_size_y;
extern int diff[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 4 (access every 4th element in round-robin fashion)
    int stride = 4;
    int offset;

    for (offset = 0; offset < stride; offset++) {
        for (i = offset; i < (block_size_y * block_size_x); i += stride) {
            sad += byte_abs[diff[i]];
        }
    }
}
