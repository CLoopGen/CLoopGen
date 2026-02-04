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
    for (bits = 1; bits <= 15; bits++) {
        if (bl_count[bits - 1] > 0) {
            code = (code + bl_count[bits - 1]) << 1;
            next_code[bits] = (ush)code;
        } else {
            next_code[bits] = 0;
        }
    }
}
