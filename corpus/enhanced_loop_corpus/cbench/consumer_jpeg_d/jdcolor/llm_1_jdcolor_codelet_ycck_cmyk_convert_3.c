#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long INT32;

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
extern INT32 *Crgtab;
extern INT32 *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION stride = 4;
    JDIMENSION block, col_local;
    for (block = 0; block < num_cols; block += stride) {
        for (col_local = 0; col_local < stride && (block + col_local) < num_cols; col_local++) {
            col = block + col_local;
            y = ((int)(inptr0[col]));
            cb = ((int)(inptr1[col]));
            cr = ((int)(inptr2[col]));
            outptr[0] = range_limit[255 - (y + Crrtab[cr])];
            outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16))))];
            outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
            outptr[3] = inptr3[col];
            outptr += 4;
        }
    }
}
