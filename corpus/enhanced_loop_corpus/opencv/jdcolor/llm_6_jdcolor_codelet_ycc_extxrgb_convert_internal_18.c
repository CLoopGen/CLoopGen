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
        int temp_cr = Crrtab[cr];
        int temp_cb = Cbbtab[cb];
        JLONG temp_crg = Crgtab[cr];
        JLONG temp_cbgtab = Cbgtab[cb];
        outptr[1] = range_limit[y + temp_cr];
        outptr[2] = range_limit[y + ((int)((temp_cbgtab + temp_crg) >> 16))];
        outptr[3] = range_limit[y + temp_cb];
        outptr[0] = 255;
        outptr += 4;
    }
}
