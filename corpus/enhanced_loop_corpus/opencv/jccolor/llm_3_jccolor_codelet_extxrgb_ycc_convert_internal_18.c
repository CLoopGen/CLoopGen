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
    const JDIMENSION stride = 4;
    JSAMPROW local_inptr = inptr;
    JSAMPROW op0 = outptr0;
    JSAMPROW op1 = outptr1;
    JSAMPROW op2 = outptr2;
    const JLONG *local_ctab = ctab;
    const int offset = 256;

    for (col = 0; col < num_cols; col++) {
        r = local_inptr[1];
        g = local_inptr[2];
        b = local_inptr[3];
        local_inptr += stride;

        op0[col] = (JSAMPLE)((local_ctab[r] + local_ctab[g + offset] + local_ctab[b + (2 * offset)]) >> 16);
        op1[col] = (JSAMPLE)((local_ctab[r + (3 * offset)] + local_ctab[g + (4 * offset)] + local_ctab[b + (5 * offset)]) >> 16);
        op2[col] = (JSAMPLE)((local_ctab[r + (6 * offset)] + local_ctab[g + (6 * offset)] + local_ctab[b + (7 * offset)]) >> 16);
    }
}
