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
JDIMENSION step = 2;
for (col = 0; col < num_cols; col += step) {
    JDIMENSION idx0 = col;
    JDIMENSION idx1 = (col + 1 < num_cols) ? col + 1 : col;

    y = inptr0[idx0];
    cb = inptr1[idx0];
    cr = inptr2[idx0];
    outptr[0] = range_limit[y + Crrtab[cr]];
    outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
    outptr[2] = range_limit[y + Cbbtab[cb]];
    outptr[3] = 255;

    y = inptr0[idx1];
    cb = inptr1[idx1];
    cr = inptr2[idx1];
    outptr[4] = range_limit[y + Crrtab[cr]];
    outptr[5] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
    outptr[6] = range_limit[y + Cbbtab[cb]];
    outptr[7] = 255;

    outptr += 8;
}
}
