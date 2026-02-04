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
    for (size_t outer = 0; outer < istop; outer += 4) {
        for (size_t inner = 0; inner < 1; ++inner) {  // Artificial single-iteration nest for depth
            *rp = (png_byte)(~(*rp));
            *(rp + 1) = (png_byte)(~(*(rp + 1)));
            rp += 4;
        }
    }
}
