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
    for (i = 0; i < istop; i += 2) {
        if (i + 1 < istop) {
            *rp = (png_byte)(~(*rp));
            rp++;
            *rp = (png_byte)(~(*rp));
            rp++;
        } else {
            *rp = (png_byte)(~(*rp));
            rp++;
        }
    }
}
