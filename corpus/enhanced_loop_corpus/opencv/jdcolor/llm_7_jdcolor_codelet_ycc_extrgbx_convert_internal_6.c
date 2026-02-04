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
    JDIMENSION idx;
    JLONG cached_Cbgtab, cached_Crgtab;
    int sum_Y_Cr, sum_Y_Cb;
    for (col = 0; col < num_cols; col++) {
        idx = col;
        y = inptr0[idx];
        cb = inptr1[idx];
        cr = inptr2[idx];
        cached_Cbgtab = Cbgtab[cb];
        cached_Crgtab = Crgtab[cr];
        sum_Y_Cr = y + Crrtab[cr];
        sum_Y_Cb = y + Cbbtab[cb];
        outptr[0] = range_limit[sum_Y_Cr];
        outptr[1] = range_limit[y + ((int)((cached_Cbgtab + cached_Crgtab) >> 16))];
        outptr[2] = range_limit[sum_Y_Cb];
        outptr[3] = 255;
        outptr += 4;
    }
}
