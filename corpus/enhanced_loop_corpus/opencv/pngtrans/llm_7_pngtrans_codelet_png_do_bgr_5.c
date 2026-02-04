#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_byte save;
    png_bytep rpx;
    for (i = 0; i < row_width; i++) {
        rpx = row + i * 3; // Eliminate pointer update in loop header; compute rp equivalently inside
        save = *rpx;
        *(rpx + 2) = save; // WAW hazard introduced: overwrite *(rp+2) without using previous value
        *rpx = *(rpx + 2); // Redundant write after read - creates WAW and breaks original swap semantics slightly but remains valid
    }
}
