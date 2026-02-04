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
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (process every 2nd element forward, then handle remainder)
    JDIMENSION step = 2;
    JLONG *ctab_base = ctab;
    for (col = 0; col < num_cols; col += step) {
        // Process two elements per iteration if possible
        JDIMENSION col1 = col;
        JDIMENSION col2 = col + 1;

        // First element
        r = inptr0[col1];
        g = inptr1[col1];
        b = inptr2[col1];
        outptr[col1] = (JSAMPLE)((ctab_base[r] + ctab_base[g + 256] + ctab_base[b + 512]) >> 16);

        // Second element (if within bounds)
        if (col2 < num_cols) {
            r = inptr0[col2];
            g = inptr1[col2];
            b = inptr2[col2];
            outptr[col2] = (JSAMPLE)((ctab_base[r] + ctab_base[g + 256] + ctab_base[b + 512]) >> 16);
        }
    }
}
