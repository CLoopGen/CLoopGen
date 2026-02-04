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



void loop() {
    png_bytep local_rp = rp;
    for (i = 0; i < istop; i += 8) {
        *(local_rp + 0) = (png_byte)(~(*(local_rp + 0)));
        *(local_rp + 2) = (png_byte)(~(*(local_rp + 2)));
        *(local_rp + 4) = (png_byte)(~(*(local_rp + 4)));
        *(local_rp + 6) = (png_byte)(~(*(local_rp + 6)));
        local_rp += 8;
    }
    rp = local_rp;
}
