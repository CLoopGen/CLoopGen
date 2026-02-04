#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided input access (process every 2nd element, then fill output densely)
    JSAMPROW local_out = outptr;
    const JSAMPROW local_in = inptr;
    JDIMENSION effective_cols = num_cols / 2; // Reduce output count based on stride
    for (JDIMENSION i = 0; i < effective_cols; i++) {
        JSAMPLE val = local_in[i * 2]; // Strided read from input
        local_out[4*i + 3] = local_out[4*i + 2] = local_out[4*i + 1] = val;
        local_out[4*i + 0] = 255;
    }
    outptr += 4 * effective_cols; // Update global outptr accordingly
}
