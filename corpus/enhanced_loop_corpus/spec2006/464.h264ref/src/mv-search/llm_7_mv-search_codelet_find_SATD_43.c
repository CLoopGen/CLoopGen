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
    sad = 0;
    for (i = 0; i < (block_size_y * block_size_x); i += 2) {
        int val1 = byte_abs[diff[i]];
        int val2 = (i + 1 < block_size_y * block_size_x) ? byte_abs[diff[i + 1]] : 0;
        sad += val1 + val2;
    }
}
