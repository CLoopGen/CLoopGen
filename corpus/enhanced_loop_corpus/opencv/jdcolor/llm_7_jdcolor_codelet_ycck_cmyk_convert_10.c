#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));
        int val0 = 255 - (y + Crrtab[cr]);
        int val1 = 255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)));
        int val2 = 255 - (y + Cbbtab[cb]);
        JSAMPLE result0 = range_limit[val0];
        JSAMPLE result1 = range_limit[val1];
        JSAMPLE result2 = range_limit[val2];
        JSAMPLE result3 = inptr3[col];
        outptr[0] = result0;
        outptr[1] = result1;
        outptr[2] = result2;
        outptr[3] = result3;
        outptr += 4;
    }
}
