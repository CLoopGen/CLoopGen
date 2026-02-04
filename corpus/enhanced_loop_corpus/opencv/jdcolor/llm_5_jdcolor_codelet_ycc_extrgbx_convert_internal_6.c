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
    
    int y_cr = y + Crrtab[cr];
    int y_cb = y + Cbbtab[cb];
    int y_cg = y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16));

    outptr[0] = (y_cr > 255) ? 255 : (y_cr < 0) ? 0 : range_limit[y_cr];
    outptr[1] = (y_cg > 255) ? 255 : (y_cg < 0) ? 0 : range_limit[y_cg];
    outptr[2] = (y_cb > 255) ? 255 : (y_cb < 0) ? 0 : range_limit[y_cb];
    outptr[3] = 255;
    
    if ((col & 3) == 0) {
        outptr[3] = 128;
    }
    outptr += 4;
}
}
