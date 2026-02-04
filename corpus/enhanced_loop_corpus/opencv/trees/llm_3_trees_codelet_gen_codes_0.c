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
    // Variant 2: Indirect array access using pointer arithmetic
    // Use pointers to simulate indirect access to bl_count and next_code
    // Maintains same computational flow but modifies memory access style
    ushf *bl_ptr = bl_count;
    ush *nc_ptr = next_code + 1;
    for (bits = 1; bits <= 15; bits++) {
        code = (code + *(bl_ptr + bits - 1)) << 1;
        *(nc_ptr++) = (ush)code;
    }
}
