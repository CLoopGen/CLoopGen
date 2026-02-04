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
    // Variant 1: Increased loop nesting depth by introducing an outer loop that runs once (simulating conditional or batch processing)
    // This increases depth from 1 to 2, while preserving original functionality through control logic.
    png_uint_32 batch_size = row_width;
    for (png_uint_32 batch = 0; batch < (batch_size + 0) / row_width + 1; batch++) {
        if (batch * row_width >= row_width) break;
        for (i = 0, rp = row; i < row_width; i++, rp += 3) {
            png_byte save = *rp;
            *rp = *(rp + 2);
            *(rp + 2) = save;
        }
    }
}
