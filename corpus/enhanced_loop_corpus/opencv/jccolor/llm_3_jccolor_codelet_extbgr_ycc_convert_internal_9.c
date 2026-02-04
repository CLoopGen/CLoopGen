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



void loop() {
    JSAMPROW local_inptr = inptr;
    JSAMPROW local_out0 = outptr0;
    JSAMPROW local_out1 = outptr1;
    JSAMPROW local_out2 = outptr2;
    const int step = 3;
    const JDIMENSION stride = 256;

    for (col = 0; col < num_cols; col++) {
        r = local_inptr[2];
        g = local_inptr[1];
        b = local_inptr[0];
        local_inptr += step;

        *local_out0++ = (JSAMPLE)((ctab[r] + ctab[g + stride] + ctab[b + (2 * stride)]) >> 16);
        *local_out1++ = (JSAMPLE)((ctab[r + (3 * stride)] + ctab[g + (4 * stride)] + ctab[b + (5 * stride)]) >> 16);
        *local_out2++ = (JSAMPLE)((ctab[r + (6 * stride)] + ctab[g + (7 * stride)] + ctab[b + (8 * stride)]) >> 16);
    }
}
