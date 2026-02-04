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
    size_t j;
    png_bytep local_rp = rp;
    for (j = 0; j < istop; j += 4) {
        if (j + 2 < istop) {
            *local_rp = (png_byte)(~(*local_rp));
            local_rp += 2;
        }
    }
    rp = local_rp;
}
