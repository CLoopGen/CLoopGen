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
    JDIMENSION col4;
    for (col4 = 0; col4 < num_cols; col4 += 4) {
        JDIMENSION base_col = col4;
        y = ((int)(inptr0[base_col]));
        cb = ((int)(inptr1[base_col]));
        cr = ((int)(inptr2[base_col]));
        outptr[0] = range_limit[255 - (y + Crrtab[cr])];
        outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16))))];
        outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[3] = inptr3[base_col];
        outptr += 4;

        if (col4 + 1 >= num_cols) continue;
        y = ((int)(inptr0[base_col + 1]));
        cb = ((int)(inptr1[base_col + 1]));
        cr = ((int)(inptr2[base_col + 1]));
        outptr[0] = range_limit[255 - (y + Crrtab[cr])];
        outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16))))];
        outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[3] = inptr3[base_col + 1];
        outptr += 4;

        if (col4 + 2 >= num_cols) continue;
        y = ((int)(inptr0[base_col + 2]));
        cb = ((int)(inptr1[base_col + 2]));
        cr = ((int)(inptr2[base_col + 2]));
        outptr[0] = range_limit[255 - (y + Crrtab[cr])];
        outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16))))];
        outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[3] = inptr3[base_col + 2];
        outptr += 4;

        if (col4 + 3 >= num_cols) continue;
        y = ((int)(inptr0[base_col + 3]));
        cb = ((int)(inptr1[base_col + 3]));
        cr = ((int)(inptr2[base_col + 3]));
        outptr[0] = range_limit[255 - (y + Crrtab[cr])];
        outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16))))];
        outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[3] = inptr3[base_col + 3];
        outptr += 4;
    }
}
