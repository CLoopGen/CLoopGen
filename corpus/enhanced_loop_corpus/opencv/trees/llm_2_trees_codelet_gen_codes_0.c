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
    // Variant 1: Strided memory access with reverse traversal
    // Instead of forward sequential access, traverse backwards with stride of 1
    // This changes data access pattern while preserving computation logic
    for (bits = 15; bits >= 1; bits--) {
        code = (code + bl_count[bits - 1]) << 1;
        next_code[bits] = (ush)code;
    }
}
