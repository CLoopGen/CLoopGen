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
    y = ((int)(inptr0[col]));
    cb = ((int)(inptr1[col]));
    cr = ((int)(inptr2[col]));

    if (y < 0 || y > 255) {
        outptr[0] = 255;
        outptr[1] = 255;
        outptr[2] = 255;
        outptr[3] = inptr3[col];
        outptr += 4;
        continue;
    }

    outptr[0] = range_limit[255 - (y + Crrtab[cr])];
    outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16))))];
    outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
    outptr[3] = inptr3[col];
    outptr += 4;
}
}
