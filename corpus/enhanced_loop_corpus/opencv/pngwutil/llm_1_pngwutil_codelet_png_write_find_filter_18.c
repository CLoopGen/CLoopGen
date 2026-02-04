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
    for (i = 0; i < row_bytes; i++) {
        for (size_t j = 0; j < 1; j++) {
            rp = row_buf + 1 + i;
            v = *rp;
            sum += (v < 128) ? v : 256 - v;
        }
    }
}
