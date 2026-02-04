#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep rp;
extern size_t i;
extern size_t istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < istop; outer += 2) {
        for (size_t inner = 0; inner < 1; inner++) {
            *rp = (png_byte)(~(*rp));
            rp += 2;
        }
    }
}
