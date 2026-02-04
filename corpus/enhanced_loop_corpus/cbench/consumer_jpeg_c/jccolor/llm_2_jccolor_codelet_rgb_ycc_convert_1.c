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
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing restructured for spatial locality
    INT32 *ctab_base_r = ctab + 0;
    INT32 *ctab_base_g = ctab + (1 * (255 + 1));
    INT32 *ctab_base_b = ctab + (2 * (255 + 1));
    INT32 *ctab_base_r1 = ctab + (3 * (255 + 1));
    INT32 *ctab_base_g1 = ctab + (4 * (255 + 1));
    INT32 *ctab_base_b1 = ctab + (5 * (255 + 1));
    INT32 *ctab_base_r2 = ctab + (5 * (255 + 1));
    INT32 *ctab_base_g2 = ctab + (6 * (255 + 1));
    INT32 *ctab_base_b2 = ctab + (7 * (255 + 1));

    JSAMPROW out0 = outptr0;
    JSAMPROW out1 = outptr1;
    JSAMPROW out2 = outptr2;
    JSAMPROW in = inptr;

    for (col = 0; col < num_cols; col++) {
        r = ((int)(in[0]));
        g = ((int)(in[1]));
        b = ((int)(in[2]));
        in += 3;

        out0[col] = (JSAMPLE)((ctab_base_r[r] + ctab_base_g[g] + ctab_base_b[b]) >> 16);
        out1[col] = (JSAMPLE)((ctab_base_r1[r] + ctab_base_g1[g] + ctab_base_b1[b]) >> 16);
        out2[col] = (JSAMPLE)((ctab_base_r2[r] + ctab_base_g2[g] + ctab_base_b2[b]) >> 16);
    }
}
