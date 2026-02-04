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
    int y_val, cb_val, cr_val;
    int computed_r, computed_g, computed_b;
    for (col = 0; col < num_cols; col++) {
        y_val = inptr0[col];
        cb_val = inptr1[col];
        cr_val = inptr2[col];

        computed_b = y_val + Cbbtab[cb_val];
        computed_g = y_val + ((int)((Cbgtab[cb_val] + Crgtab[cr_val]) >> 16));
        computed_r = y_val + Crrtab[cr_val];

        outptr[0] = range_limit[computed_b];
        outptr[1] = range_limit[computed_g];
        outptr[2] = range_limit[computed_r];
        outptr[3] = 255;

        outptr += 4;
    }
}
