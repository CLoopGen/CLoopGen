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
    // Variant 1: Consecutive memory access with loop unrolling by 2
    JDIMENSION col;
    for (col = 0; col < num_cols - 1; col += 2) {
        // Process two pixels at a time, accessing data consecutively
        int y0 = ((int)(inptr0[col]));
        int cb0 = ((int)(inptr1[col]));
        int cr0 = ((int)(inptr2[col]));
        outptr[0] = range_limit[y0 + Crrtab[cr0]];
        outptr[1] = range_limit[y0 + ((int)((Cbgtab[cb0] + Crgtab[cr0]) >> 16))];
        outptr[2] = range_limit[y0 + Cbbtab[cb0]];

        int y1 = ((int)(inptr0[col + 1]));
        int cb1 = ((int)(inptr1[col + 1]));
        int cr1 = ((int)(inptr2[col + 1]));
        outptr[3] = range_limit[y1 + Crrtab[cr1]];
        outptr[4] = range_limit[y1 + ((int)((Cbgtab[cb1] + Crgtab[cr1]) >> 16))];
        outptr[5] = range_limit[y1 + Cbbtab[cb1]];

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
