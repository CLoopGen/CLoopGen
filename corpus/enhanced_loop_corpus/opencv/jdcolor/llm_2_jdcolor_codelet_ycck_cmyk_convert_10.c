#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern int y;
extern int cb;
extern int cr;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JSAMPROW inptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern INT32 *Crgtab;
extern INT32 *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling by 2
    JDIMENSION col4 = num_cols & ~3;  // Round down to multiple of 4
    for (col = 0; col < col4; col += 4) {
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));
        outptr[0] = range_limit[255 - (y + Crrtab[cr])];
        outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
        outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[3] = inptr3[col];

        y = ((int)(inptr0[col+1]));
        cb = ((int)(inptr1[col+1]));
        cr = ((int)(inptr2[col+1]));
        outptr[4] = range_limit[255 - (y + Crrtab[cr])];
        outptr[5] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
        outptr[6] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[7] = inptr3[col+1];

        y = ((int)(inptr0[col+2]));
        cb = ((int)(inptr1[col+2]));
        cr = ((int)(inptr2[col+2]));
        outptr[8] = range_limit[255 - (y + Crrtab[cr])];
        outptr[9] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
        outptr[10] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[11] = inptr3[col+2];

        y = ((int)(inptr0[col+3]));
        cb = ((int)(inptr1[col+3]));
        cr = ((int)(inptr2[col+3]));
        outptr[12] = range_limit[255 - (y + Crrtab[cr])];
        outptr[13] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
        outptr[14] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[15] = inptr3[col+3];

        outptr += 16;
    }
    // Handle remaining elements
    for (; col < num_cols; col++) {
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));
        outptr[0] = range_limit[255 - (y + Crrtab[cr])];
        outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
        outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[3] = inptr3[col];
        outptr += 4;
    }
}
