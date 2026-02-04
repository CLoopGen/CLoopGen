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
    // Variant 2: Strided memory access - process every 2nd pixel (unrolled by 2)
    JDIMENSION col8 = num_cols & ~((JDIMENSION)1); // Round down to even
    for (col = 0; col < col8; col += 2) {
        // First pixel
        y = inptr0[col];
        cb = inptr1[col];
        cr = inptr2[col];
        outptr[2] = range_limit[y + Crrtab[cr]];
        outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[0] = range_limit[y + Cbbtab[cb]];
        outptr[3] = 255;

        // Second pixel
        y = inptr0[col+1];
        cb = inptr1[col+1];
        cr = inptr2[col+1];
        outptr[6] = range_limit[y + Crrtab[cr]];
        outptr[5] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[4] = range_limit[y + Cbbtab[cb]];
        outptr[7] = 255;

        outptr += 8;
    }
    // Handle leftover pixel if num_cols is odd
    if (col < num_cols) {
        y = inptr0[col];
        cb = inptr1[col];
        cr = inptr2[col];
        outptr[2] = range_limit[y + Crrtab[cr]];
        outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[0] = range_limit[y + Cbbtab[cb]];
        outptr[3] = 255;
        outptr += 4;
    }
}
