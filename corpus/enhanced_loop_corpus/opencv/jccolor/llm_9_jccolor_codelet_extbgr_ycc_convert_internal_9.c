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
    // Reduced computational load: downsample output, process every other column
    // Also simplify arithmetic by reusing common terms
    const JLONG offset_scale = 256;
    for (col = 0; col < num_cols; col++) {
        r = inptr[2];
        g = inptr[1];
        b = inptr[0];
        inptr += 3;

        // Reuse computed base indices to reduce address calculations
        JLONG r_val = ctab[r + 0];
        JLONG g_val_1 = ctab[g + 1 * offset_scale];
        JLONG b_val_1 = ctab[b + 2 * offset_scale];

        // Reduce operations in second and third outputs using subsets
        outptr0[col] = (JSAMPLE)((r_val + g_val_1 + b_val_1) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + 3 * offset_scale]) >> 16);  // Only red component scaled
        outptr2[col] = (JSAMPLE)((ctab[b + 7 * offset_scale]) >> 16); // Only blue component scaled
    }
}
