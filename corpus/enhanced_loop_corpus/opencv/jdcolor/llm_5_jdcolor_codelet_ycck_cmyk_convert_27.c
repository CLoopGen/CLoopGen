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
extern JSAMPROW inptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern JLONG *Crgtab;
extern JLONG *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (col = 0; col < num_cols; col++) {
    y = inptr0[col];
    cb = inptr1[col];
    cr = inptr2[col];

    int cr_val = Crrtab[cr];
    int cb_val = Cbbtab[cb];
    int cg_val = (int)((Cbgtab[cb] + Crgtab[cr]) >> 16);

    int y_plus_cr = y + cr_val;
    int y_plus_cg = y + cg_val;
    int y_plus_cb = y + cb_val;

    if (y_plus_cr < 255) {
        outptr[0] = range_limit[255 - y_plus_cr];
    } else {
        outptr[0] = 0;
    }

    if (y_plus_cg > 255) {
        outptr[1] = range_limit[255 - (y_plus_cg & 255)];
    } else {
        outptr[1] = range_limit[255];
    }

    if (y_plus_cb != 0) {
        outptr[2] = range_limit[255 - y_plus_cb];
    } else {
        outptr[2] = 255;
    }

    outptr[3] = inptr3[col];
    outptr += 4;
}
}
