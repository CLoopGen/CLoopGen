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
    JDIMENSION idx = 0;
    for (col = 0; col < num_cols; col++) {
        y = inptr0[col];
        cb = inptr1[col];
        cr = inptr2[col];
        int temp_y = y;
        outptr[idx + 0] = 255;
        outptr[idx + 1] = range_limit[temp_y + Cbbtab[cb]];
        outptr[idx + 2] = range_limit[temp_y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[idx + 3] = range_limit[temp_y + Crrtab[cr]];
        idx += 4;
    }
}
