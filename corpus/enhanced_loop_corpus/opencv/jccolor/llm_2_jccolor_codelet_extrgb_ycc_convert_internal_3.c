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
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed indices and coalesced ctab lookups
    JLONG *ctab_base_r = ctab;
    JLONG *ctab_base_g = ctab + (255 + 1);
    JLONG *ctab_base_b = ctab + (2 * (255 + 1));
    JLONG *ctab_ext1 = ctab + (3 * (255 + 1));
    JLONG *ctab_ext2 = ctab + (4 * (255 + 1));
    JLONG *ctab_ext3 = ctab + (5 * (255 + 1));
    JLONG *ctab_ext4 = ctab + (6 * (255 + 1));
    JLONG *ctab_ext5 = ctab + (7 * (255 + 1));

    JSAMPROW out0 = outptr0;
    JSAMPROW out1 = outptr1;
    JSAMPROW out2 = outptr2;

    for (col = 0; col < num_cols; col++) {
        r = inptr[0];
        g = inptr[1];
        b = inptr[2];
        inptr += 3;

        out0[col] = (JSAMPLE)((ctab_base_r[r] + ctab_base_g[g] + ctab_base_b[b]) >> 16);
        out1[col] = (JSAMPLE)((ctab_ext1[r] + ctab_ext2[g] + ctab_ext3[b]) >> 16);
        out2[col] = (JSAMPLE)((ctab_ext3[r] + ctab_ext4[g] + ctab_ext5[b]) >> 16);
    }
}
