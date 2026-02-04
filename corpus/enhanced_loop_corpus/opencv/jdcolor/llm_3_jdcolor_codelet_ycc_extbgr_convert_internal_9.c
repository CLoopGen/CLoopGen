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
    JDIMENSION stride = 2;
    for (col = 0; col < num_cols; col += stride) {
        JDIMENSION end_col = col + stride <= num_cols ? col + stride : num_cols;
        for (JDIMENSION inner = col; inner < end_col; inner++) {
            y = inptr0[inner];
            cb = inptr1[inner];
            cr = inptr2[inner];
            outptr[2] = range_limit[y + Crrtab[cr]];
            outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
            outptr[0] = range_limit[y + Cbbtab[cb]];
            outptr += 3;
        }
    }
}
