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
    JDIMENSION stride = (num_cols + 3) / 4;
    for (col = 0; col < stride; col++) {
        JDIMENSION base_col = col * 4;
        if (base_col < num_cols) {
            y = inptr0[base_col];
            cb = inptr1[base_col];
            cr = inptr2[base_col];
            outptr[2] = range_limit[y + Crrtab[cr]];
            outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
            outptr[0] = range_limit[y + Cbbtab[cb]];
            outptr[3] = 255;
            outptr += 4;
        }
        if (base_col + 1 < num_cols) {
            y = inptr0[base_col + 1];
            cb = inptr1[base_col + 1];
            cr = inptr2[base_col + 1];
            outptr[2] = range_limit[y + Crrtab[cr]];
            outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
            outptr[0] = range_limit[y + Cbbtab[cb]];
            outptr[3] = 255;
            outptr += 4;
        }
        if (base_col + 2 < num_cols) {
            y = inptr0[base_col + 2];
            cb = inptr1[base_col + 2];
            cr = inptr2[base_col + 2];
            outptr[2] = range_limit[y + Crrtab[cr]];
            outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
            outptr[0] = range_limit[y + Cbbtab[cb]];
            outptr[3] = 255;
            outptr += 4;
        }
        if (base_col + 3 < num_cols) {
            y = inptr0[base_col + 3];
            cb = inptr1[base_col + 3];
            cr = inptr2[base_col + 3];
            outptr[2] = range_limit[y + Crrtab[cr]];
            outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
            outptr[0] = range_limit[y + Cbbtab[cb]];
            outptr[3] = 255;
            outptr += 4;
        }
    }
}
