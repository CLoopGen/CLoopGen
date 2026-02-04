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
    JSAMPROW local_inptr = inptr;
    JLONG *local_ctab = ctab;
    JSAMPROW local_out0 = outptr0;
    JSAMPROW local_out1 = outptr1;
    JSAMPROW local_out2 = outptr2;

    for (col = 0; col < num_cols; col++) {
        r = local_inptr[2];
        g = local_inptr[1];
        b = local_inptr[0];
        local_inptr += 4;

        local_out0[col] = (JSAMPLE)(((local_ctab[r + 0] + local_ctab[g + 256] + local_ctab[b + 512]) >> 16));
        local_out1[col] = (JSAMPLE)(((local_ctab[r + 768] + local_ctab[g + 1024] + local_ctab[b + 1280]) >> 16));
        local_out2[col] = (JSAMPLE)(((local_ctab[r + 1280] + local_ctab[g + 1536] + local_ctab[b + 1792]) >> 16));
    }
}
