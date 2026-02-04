#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern int y;
extern int cb;
extern int cr;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern JLONG *Crgtab;
extern JLONG *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 2nd pixel (unrolled by 2) to create stride
    JDIMENSION col8 = num_cols & ~1U; // Round down to even number for safe unrolling
    for (col = 0; col < col8; col += 2) {
        // Process two pixels at once with strided writes
        int idx0 = col, idx1 = col + 1;

        y = inptr0[idx0]; cb = inptr1[idx0]; cr = inptr2[idx0];
        outptr[3] = range_limit[y + Crrtab[cr]];
        outptr[2] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[1] = range_limit[y + Cbbtab[cb]];
        outptr[0] = 255;

        y = inptr0[idx1]; cb = inptr1[idx1]; cr = inptr2[idx1];
        outptr[7] = range_limit[y + Crrtab[cr]];
        outptr[6] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[5] = range_limit[y + Cbbtab[cb]];
        outptr[4] = 255;

        outptr += 8; // Stride of 8 bytes (2 pixels * 4 components)
    }
    // Handle leftover pixel if num_cols is odd
    if (col < num_cols) {
        y = inptr0[col];
        cb = inptr1[col];
        cr = inptr2[col];
        outptr[3] = range_limit[y + Crrtab[cr]];
        outptr[2] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[1] = range_limit[y + Cbbtab[cb]];
        outptr[0] = 255;
        outptr += 4;
    }
}
