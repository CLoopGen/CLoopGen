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
    // Variant 2: Strided memory access - process every 2nd element first, then the rest
    JSAMPROW out_base = outptr;
    const JSAMPROW in = inptr;
    JDIMENSION stride = 2;
    JDIMENSION phase, col;

    // Process in two phases with strided access pattern
    for (phase = 0; phase < stride; phase++) {
        JSAMPROW out = out_base + phase * 4;
        for (col = phase; col < num_cols; col += stride) {
            JSAMPLE val = in[col];
            out[0] = val;
            out[1] = val;
            out[2] = val;
            out[3] = 255;
            out += stride * 4;  // Maintain strided output layout
        }
    }
    // Note: This variant assumes interleaved output layout is acceptable.
    // In practice, a final reorganization might be needed, but omitted here
    // to maintain functional equivalence under strided interpretation.
}
