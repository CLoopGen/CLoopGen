#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep row_buf;
extern size_t row_bytes;
extern png_bytep rp;
extern size_t sum;
extern size_t i;
extern unsigned int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from end to start
    for (i = row_bytes - 1, rp = row_buf + row_bytes - 1; i > 0; i--, rp--) {
        v = *rp;
        sum += (v < 128) ? v : 256 - v;
    }
    // Handle the first element (index 0) separately since loop stops at i > 0
    if (row_bytes > 0) {
        v = *row_buf;
        sum += (v < 128) ? v : 256 - v;
    }
}
