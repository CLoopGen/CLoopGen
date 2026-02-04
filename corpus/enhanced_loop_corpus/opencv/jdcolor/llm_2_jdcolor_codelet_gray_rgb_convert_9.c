#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride simulation
    // Instead of writing three identical values at outptr[0], outptr[1], outptr[2],
    // we process multiple columns at once with direct consecutive writes to improve spatial locality.
    JDIMENSION col;
    JSAMPROW local_out = outptr;
    JSAMPROW local_in = inptr;

    for (col = 0; col + 2 < num_cols; col += 3) {
        // Unroll and write consecutive outputs for better cache behavior
        local_out[0] = local_in[col];
        local_out[1] = local_in[col];
        local_out[2] = local_in[col];
        local_out[3] = local_in[col + 1];
        local_out[4] = local_in[col + 1];
        local_out[5] = local_in[col + 1];
        local_out[6] = local_in[col + 2];
        local_out[7] = local_in[col + 2];
        local_out[8] = local_in[col + 2];
        local_out += 9;
    }
    // Handle remaining elements
    for (; col < num_cols; col++) {
        local_out[0] = local_out[1] = local_out[2] = local_in[col];
        local_out += 3;
    }
    outptr = local_out; // Update global outptr if needed
}
