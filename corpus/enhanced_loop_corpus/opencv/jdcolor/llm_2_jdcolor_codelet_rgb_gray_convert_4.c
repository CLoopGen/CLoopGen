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
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    JDIMENSION col_even;
    for (col_even = 0; col_even < num_cols; col_even += 2) {
        y = Rytab[((int)(inptr0[col_even]))];
        y += Gytab[((int)(inptr1[col_even]))];
        y += Bytab[((int)(inptr2[col_even]))];
        outptr[col_even] = (JSAMPLE)(y >> 16);
    }
    for (JDIMENSION col_odd = 1; col_odd < num_cols; col_odd += 2) {
        y = Rytab[((int)(inptr0[col_odd]))];
        y += Gytab[((int)(inptr1[col_odd]))];
        y += Bytab[((int)(inptr2[col_odd]))];
        outptr[col_odd] = (JSAMPLE)(y >> 16);
    }
}
