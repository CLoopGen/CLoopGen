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
    for (i = 0, rp = row_buf + 1; i < row_bytes; i++, rp++) {
        v = *rp;
        if (v >= 128) {
            sum += 256 - v;
        } else {
            sum += v;
        }
    }
}
