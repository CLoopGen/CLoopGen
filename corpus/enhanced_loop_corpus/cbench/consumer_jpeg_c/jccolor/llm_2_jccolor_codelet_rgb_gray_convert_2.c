#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern INT32 *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base offset precomputation
    INT32 *ctab_r = ctab;
    INT32 *ctab_g = ctab + (1 * (256));
    INT32 *ctab_b = ctab + (2 * (256));
    JSAMPROW inptr_local = inptr;
    for (col = 0; col < num_cols; col++) {
        r = ((int)(inptr_local[0]));
        g = ((int)(inptr_local[1]));
        b = ((int)(inptr_local[2]));
        inptr_local += 3;
        outptr[col] = (JSAMPLE)((ctab_r[r] + ctab_g[g] + ctab_b[b]) >> 16);
    }
}
