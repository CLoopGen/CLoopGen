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
    JLONG temp_rg_val;
    int temp_y, temp_cb, temp_cr;
    for (col = 0; col < num_cols; col++) {
        temp_y = inptr0[col];
        temp_cb = inptr1[col];
        temp_cr = inptr2[col];
        temp_rg_val = (Cbgtab[temp_cb] + Crgtab[temp_cr]) >> 16;
        outptr[0] = range_limit[temp_y + Crrtab[temp_cr]];
        outptr[1] = range_limit[temp_y + temp_rg_val];
        outptr[2] = range_limit[temp_y + Cbbtab[temp_cb]];
        outptr += 3;
    }
}
