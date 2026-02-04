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
    for (col = 0; col < num_cols; col++) {
        y = ((int)(inptr0[col])) >> 1;
        cb = ((int)(inptr1[col])) - 128;
        cr = ((int)(inptr2[col])) - 128;
        int cr_adj = Crrtab[cr + 128];
        int cb_adj = Cbbtab[cb + 128];
        INT32 cg_adj = (Cbgtab[cb + 128] + Crgtab[cr + 128]) >> 16;
        y = (y << 1) + 128;
        outptr[0] = range_limit[382 - (y + cr_adj)];
        outptr[1] = range_limit[382 - (y + ((int)(cg_adj)))];
        outptr[2] = range_limit[382 - (y + cb_adj)];
        outptr[3] = inptr3[col];
        outptr += 4;
    }
}
