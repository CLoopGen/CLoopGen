#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep rp;
extern png_uint_32 i;
extern png_uint_32 istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_bytep local_rp = rp;
    png_uint_32 unrolled_count = istop & ~3; // Round down to multiple of 4
    png_uint_32 i = 0;

    // Unrolled loop with reduced loop-carried dependency (WAW on i removed via unrolling)
    for (; i < unrolled_count; i += 4, local_rp += 8) {
        png_byte t0 = local_rp[0], t1 = local_rp[2], t2 = local_rp[4], t3 = local_rp[6];
        local_rp[0] = local_rp[1]; local_rp[1] = t0;
        local_rp[2] = local_rp[3]; local_rp[3] = t1;
        local_rp[4] = local_rp[5]; local_rp[5] = t2;
        local_rp[6] = local_rp[7]; local_rp[7] = t3;
    }

    // Cleanup loop for remaining iterations
    for (; i < istop; i++, local_rp += 2) {
        png_byte t = *local_rp;
        *local_rp = *(local_rp + 1);
        *(local_rp + 1) = t;
    }
}
