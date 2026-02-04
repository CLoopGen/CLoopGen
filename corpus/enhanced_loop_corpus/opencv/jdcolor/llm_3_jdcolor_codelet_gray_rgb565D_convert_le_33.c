#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JSAMPLE *range_limit;
extern JDIMENSION num_cols;
extern JLONG d0;
extern JLONG rgb;
extern unsigned int g;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access — process every other pixel pair with stride of 4 bytes in input
    JDIMENSION col;
    JSAMPROW base_in = inptr;
    JSAMPROW base_out = outptr;
    JLONG d0_local = d0;
    JLONG rgb_local;
    unsigned int g;

    // Simulate strided access: step by 2 elements but read from spaced locations
    for (col = 0; col < (num_cols >> 2); col++) {  // Note: adjusted bound due to effective doubling
        // Stride: access elements at positions 2*col and 2*col+1, but from a base incremented by 2 each time
        JDIMENSION idx1 = col * 4;     // Stride of 4 in byte index
        JDIMENSION idx2 = idx1 + 1;

        g = base_in[idx1];
        g = range_limit[g + (d0_local & 255)];
        rgb_local = ((g << 8) & 63488) | ((g << 3) & 2016) | (g >> 3);
        d0_local = ((d0_local & 255) << 24) | ((d0_local >> 8) & 16777215);

        g = base_in[idx2];
        g = range_limit[g + (d0_local & 255)];
        rgb_local = ((((((g << 8) & 63488) | ((g << 3) & 2016) | (g >> 3)) << 16) | rgb_local));
        d0_local = ((d0_local & 255) << 24) | ((d0_local >> 8) & 16777215);

        // Output written consecutively
        ((*(int *)(base_out + (col * 4)))) = rgb_local;
    }

    // Update globals to reflect progress (approximate)
    inptr = base_in + (col * 4) + 1;
    outptr = base_out + (col * 4);
    d0 = d0_local;
}
