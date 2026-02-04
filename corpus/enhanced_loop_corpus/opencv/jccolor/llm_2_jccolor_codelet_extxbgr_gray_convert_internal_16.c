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
    // Variant 1: Consecutive memory access with manual offset advancement
    // Instead of accessing inptr[3], inptr[2], inptr[1] non-sequentially, we reorganize to read sequentially
    // and adjust the order of operations accordingly. Also process data in batches if needed.
    JLONG *ctab_base_r = ctab;
    JLONG *ctab_base_g = ctab + (1 * (256));
    JLONG *ctab_base_b = ctab + (2 * (256));
    
    JSAMPROW local_inptr = inptr;
    JSAMPROW local_outptr = outptr;

    for (col = 0; col < num_cols; col++) {
        int b_val = local_inptr[1];
        int g_val = local_inptr[2];
        int r_val = local_inptr[3];
        local_inptr += 4;
        local_outptr[col] = (JSAMPLE)((ctab_base_r[r_val] + ctab_base_g[g_val] + ctab_base_b[b_val]) >> 16);
    }
}
