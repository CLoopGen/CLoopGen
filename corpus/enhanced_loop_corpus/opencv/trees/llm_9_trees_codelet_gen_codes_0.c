#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short ush;

typedef ush ushf;

extern ushf *bl_count;
extern ush next_code[16];
extern unsigned int code;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified operations but added memory access pattern variation
    // Trip count halved, but each iteration performs dual updates using strided array access
    for (bits = 2; bits <= 15; bits += 2) {
        unsigned int temp1 = (code + bl_count[bits - 2]) << 1;
        unsigned int temp2 = (temp1 + bl_count[bits - 1]) << 1;
        next_code[bits - 1] = (ush)temp1;
        next_code[bits]     = (ush)temp2;
        code = temp2;
    }
    // Final cleanup for possible odd upper bound
    if (bits > 15 && (bits - 2) < 15) {
        next_code[15] = (ush)((code + bl_count[14]) << 1);
    }
}
