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
    JDIMENSION col2;
    for (col = 0, col2 = 0; col < num_cols; col++, col2 += 3) {
        y = inptr0[col];
        cb = inptr1[col];
        cr = inptr2[col];
        JSAMPROW row = &outptr[col2];
        JLONG cbg_val = Cbgtab[cb];
        JLONG crg_val = Crgtab[cr];
        int index_r = y + Crrtab[cr];
        int index_g = y + ((int)((cbg_val + crg_val) >> 16));
        int index_b = y + Cbbtab[cb];
        row[2] = range_limit[index_r];
        row[1] = range_limit[index_g];
        row[0] = range_limit[index_b];
    }
}
