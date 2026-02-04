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
    // Variant 1: Consecutive memory access with manual pointer arithmetic unrolled by 2 iterations
    JDIMENSION col;
    JSAMPROW local_in = inptr;
    JSAMPROW local_out = outptr;
    JLONG d0_local = d0;
    JLONG rgb_local;
    unsigned int g1, g2;

    for (col = 0; col < (num_cols >> 1); col++) {
        // Load two consecutive input samples without intermediate side effects on global inptr
        g1 = *(local_in + 0);
        g2 = *(local_in + 1);

        // Process first sample
        g1 = range_limit[g1 + (d0_local & 255)];
        rgb_local = ((g1 << 8) & 63488) | ((g1 << 3) & 2016) | (g1 >> 3);

        // Update d0_local for second sample
        d0_local = ((d0_local & 255) << 24) | ((d0_local >> 8) & 16777215);

        // Process second sample
        g2 = range_limit[g2 + (d0_local & 255)];
        rgb_local |= (((((g2 << 8) & 63488) | ((g2 << 3) & 2016) | (g2 >> 3)) << 16));

        // Update d0_local after second sample
        d0_local = ((d0_local & 255) << 24) | ((d0_local >> 8) & 16777215);

        // Store result using direct integer pointer cast
        *(int*)local_out = rgb_local;

        // Advance pointers manually
        local_in += 2;
        local_out += 4;
    }

    // Update global pointers if needed by caller
    inptr = local_in;
    outptr = local_out;
    d0 = d0_local;
}
