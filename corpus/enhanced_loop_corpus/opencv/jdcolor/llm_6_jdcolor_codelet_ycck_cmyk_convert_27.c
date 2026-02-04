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
extern JSAMPROW inptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern JLONG *Crgtab;
extern JLONG *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_y, temp_cb, temp_cr;
    for (col = 0; col < num_cols; col++) {
        temp_y = inptr0[col];
        temp_cb = inptr1[col];
        temp_cr = inptr2[col];
        y = temp_y;
        cb = temp_cb;
        cr = temp_cr;
        outptr[0] = range_limit[255 - (y + Crrtab[cr])];
        outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
        outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[3] = inptr3[col];
        outptr += 4;
    }
}
