#include <stdio.h>

#include <inttypes.h>

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
    // Variant 1: Consecutive Memory Access with Loop Unrolling (factor of 2)
    // Arrays are accessed in a more cache-friendly, consecutive manner by unrolling the loop.
    // This reduces address computation overhead and improves spatial locality.

    JDIMENSION col = 0;
    for (; col + 1 < num_cols; col += 2) {
        // Process two pixels per iteration
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));

        outptr[0] = range_limit[y + Crrtab[cr]];
        outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[2] = range_limit[y + Cbbtab[cb]];

        y = ((int)(inptr0[col + 1]));
        cb = ((int)(inptr1[col + 1]));
        cr = ((int)(inptr2[col + 1]));

        outptr[3] = range_limit[y + Crrtab[cr]];
        outptr[4] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[5] = range_limit[y + Cbbtab[cb]];

        outptr += 6;
    }
    // Handle remaining pixel if num_cols is odd
    if (col < num_cols) {
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));
        outptr[0] = range_limit[y + Crrtab[cr]];
        outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[2] = range_limit[y + Cbbtab[cb]];
        outptr += 3;
    }
}
