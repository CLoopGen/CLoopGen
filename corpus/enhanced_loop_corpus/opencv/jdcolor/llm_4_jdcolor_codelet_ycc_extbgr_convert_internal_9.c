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
for (col = 0; col < num_cols; col++) {
    y = inptr0[col];
    cb = inptr1[col];
    cr = inptr2[col];
    int cr_val = Crrtab[cr];
    int cb_val = Cbbtab[cb];
    int cg_val = (int)((Cbgtab[cb] + Crgtab[cr]) >> 16);
    
    if (cr_val >= 0 && cb_val >= 0) {
        outptr[2] = range_limit[y + cr_val];
        outptr[0] = range_limit[y + cb_val];
        outptr[1] = range_limit[y + cg_val];
    } else {
        outptr[2] = range_limit[y];
        outptr[1] = range_limit[y];
        outptr[0] = range_limit[y];
    }
    outptr += 3;
}
}
