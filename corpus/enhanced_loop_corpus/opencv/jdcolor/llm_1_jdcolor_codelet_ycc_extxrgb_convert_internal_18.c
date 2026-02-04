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
    if (num_cols > 0) {
        col = 0;
        for (; col < num_cols - 3; col += 4) {
            JDIMENSION i;
            for (i = 0; i < 4; i++) {
                JDIMENSION idx = col + i;
                y = inptr0[idx];
                cb = inptr1[idx];
                cr = inptr2[idx];
                outptr[1] = range_limit[y + Crrtab[cr]];
                outptr[2] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
                outptr[3] = range_limit[y + Cbbtab[cb]];
                outptr[0] = 255;
                outptr += 4;
            }
        }
        for (; col < num_cols; col++) {
            y = inptr0[col];
            cb = inptr1[col];
            cr = inptr2[col];
            outptr[1] = range_limit[y + Crrtab[cr]];
            outptr[2] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
            outptr[3] = range_limit[y + Cbbtab[cb]];
            outptr[0] = 255;
            outptr += 4;
        }
    }
}
