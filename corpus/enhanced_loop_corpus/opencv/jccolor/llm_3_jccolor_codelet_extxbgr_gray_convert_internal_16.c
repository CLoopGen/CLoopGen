#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JLONG *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Access input buffer using a stride of 4 from base address, but traverse components via fixed offsets
    // Simulate a structure-of-arrays (SoA) layout from interleaved data by precomputing strides
    JSAMPROW base_inptr = inptr - 4; // Adjust so we can use positive indexing starting at 0
    JSAMPROW local_outptr = outptr;

    for (col = 0; col < num_cols; col++) {
        JDIMENSION idx = col * 4;
        r = base_inptr[idx + 3];
        g = base_inptr[idx + 2];
        b = base_inptr[idx + 1];
        local_outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
    }
}
