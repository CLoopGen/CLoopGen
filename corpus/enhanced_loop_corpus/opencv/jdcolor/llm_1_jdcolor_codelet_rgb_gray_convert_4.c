#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern INT32 y;
extern INT32 *Rytab;
extern INT32 *Gytab;
extern INT32 *Bytab;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION stride = 4;
    JDIMENSION col;
    for (col = 0; col + stride <= num_cols; col += stride) {
        y = Rytab[((int)(inptr0[col]))];
        y += Gytab[((int)(inptr1[col]))];
        y += Bytab[((int)(inptr2[col]))];
        outptr[col] = (JSAMPLE)(y >> 16);

        y = Rytab[((int)(inptr0[col+1]))];
        y += Gytab[((int)(inptr1[col+1]))];
        y += Bytab[((int)(inptr2[col+1]))];
        outptr[col+1] = (JSAMPLE)(y >> 16);

        y = Rytab[((int)(inptr0[col+2]))];
        y += Gytab[((int)(inptr1[col+2]))];
        y += Bytab[((int)(inptr2[col+2]))];
        outptr[col+2] = (JSAMPLE)(y >> 16);

        y = Rytab[((int)(inptr0[col+3]))];
        y += Gytab[((int)(inptr1[col+3]))];
        y += Bytab[((int)(inptr2[col+3]))];
        outptr[col+3] = (JSAMPLE)(y >> 16);
    }
    for (; col < num_cols; col++) {
        y = Rytab[((int)(inptr0[col]))];
        y += Gytab[((int)(inptr1[col]))];
        y += Bytab[((int)(inptr2[col]))];
        outptr[col] = (JSAMPLE)(y >> 16);
    }
}
