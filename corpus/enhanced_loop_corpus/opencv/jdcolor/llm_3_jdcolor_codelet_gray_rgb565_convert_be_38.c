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
extern JDIMENSION num_cols;
extern JLONG rgb;
extern unsigned int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every second pixel pair (strided by 2)
    JDIMENSION step = 2;
    JDIMENSION limit = (num_cols >> 1);
    JSAMPROW in_base = inptr;
    JSAMPROW out_base = outptr;

    // Only process indices where col % step == 0, simulating strided traversal
    for (col = 0; col < limit; col += step) {
        // Access elements with stride: read from inptr[col*2] and inptr[col*2+1], etc.
        JSAMPROW in_offset = in_base + (col << 1);  // Each iteration uses two samples

        g = in_offset[0];
        rgb = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
        g = in_offset[1];
        rgb = ((rgb << 16) | (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936)));

        ((*(int *)(out_base + (col * 4)))) = rgb;  // Output spaced by 4 bytes per valid col
    }

    // Update global pointers only if full traversal occurred (approximate semantics)
    // Note: This variant does not fully consume input, so pointer updates are semantic
    if (limit > 0) {
        JDIMENSION last_idx = ((limit - 1) / step) * step;
        inptr = in_base + (last_idx << 1) + 2;
        outptr = out_base + (last_idx * 4) + 4;
    }
}
