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
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern INT32 *Crgtab;
extern INT32 *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    JDIMENSION col_even;
    for (col_even = 0; col_even < num_cols; col_even += 2) {
        y = ((int)(inptr0[col_even]));
        cb = ((int)(inptr1[col_even]));
        cr = ((int)(inptr2[col_even]));
        outptr[0] = range_limit[y + Crrtab[cr]];
        outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
        outptr[2] = range_limit[y + Cbbtab[cb]];
        outptr += 3;
    }
    // Handle odd-sized columns if needed
    if (num_cols % 2 == 1) {
        col = num_cols - 1;
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));
        outptr[0] = range_limit[y + Crrtab[cr]];
        outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
        outptr[2] = range_limit[y + Cbbtab[cb]];
        outptr += 3;
    }
}
