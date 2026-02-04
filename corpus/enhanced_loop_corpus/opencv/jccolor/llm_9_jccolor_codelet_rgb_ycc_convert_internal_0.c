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
    const JDIMENSION unroll_factor = 4;
    JDIMENSION limit = (num_cols / unroll_factor) * unroll_factor;
    for (col = 0; col < limit; col += unroll_factor) {
        for (int k = 0; k < unroll_factor; ++k) {
            int idx = k * 3;
            r = inptr[idx + 0];
            g = inptr[idx + 1];
            b = inptr[idx + 2];
            outptr0[col + k] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
            outptr1[col + k] = (JSAMPLE)((ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280]) >> 16);
            outptr2[col + k] = (JSAMPLE)((ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792]) >> 16);
        }
        inptr += 3 * unroll_factor;
    }
    for (; col < num_cols; col++) {
        r = inptr[0]; g = inptr[1]; b = inptr[2];
        inptr += 3;
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792]) >> 16);
    }
}
