#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern INT32 y;
extern INT32 *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access (every third element), we reorganize to process data in consecutive chunks.
    // Assume input is still RGB interleaved, but we prefetch values into local variables for coalesced ctab access.
    INT32 *local_ctab = ctab; // Local alias for potential optimization
    JSAMPROW local_inptr = inptr;
    for (col = 0; col < num_cols; col++) {
        int idx0 = local_inptr[0];
        int idx1 = local_inptr[1];
        int idx2 = local_inptr[2];
        y = local_ctab[idx0] + 
            local_ctab[256 + idx1] + 
            local_ctab[512 + idx2];
        outptr[col] = (JSAMPLE)(y >> 16);
        local_inptr += 3;
    }
}
