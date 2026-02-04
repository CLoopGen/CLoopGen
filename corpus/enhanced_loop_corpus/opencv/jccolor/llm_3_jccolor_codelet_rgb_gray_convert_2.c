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
    // Variant 2: Indirect Memory Access Pattern
    // Use an index array to perform indirect addressing into ctab.
    // Simulates a scenario where lookup indices are precomputed or dynamically indexed.
    static const int offsets[] = {0, 256, 512}; // Precomputed base offsets: 0, 1*(255+1), 2*(255+1)
    const int *idx_map = offsets;
    for (col = 0; col < num_cols; col++) {
        y = ctab[idx_map[0] + inptr[0]];
        y += ctab[idx_map[1] + inptr[1]];
        y += ctab[idx_map[2] + inptr[2]];
        inptr += 3;
        outptr[col] = (JSAMPLE)(y >> 16);
    }
}
