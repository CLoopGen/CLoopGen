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
    for (col = 0; col < num_cols; col += 2) {
        y = inptr0[col];
        cb = inptr1[col];
        cr = inptr2[col];
        outptr[1] = range_limit[y + Crrtab[cr]];
        outptr[2] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
        outptr[3] = range_limit[y + Cbbtab[cb]];
        outptr[0] = 255;
        
        if (col + 1 < num_cols) {
            int y2 = inptr0[col + 1];
            int cb2 = inptr1[col + 1];
            int cr2 = inptr2[col + 1];
            outptr[5] = range_limit[y2 + Crrtab[cr2]];
            outptr[6] = range_limit[y2 + ((int)((Cbgtab[cb2] + Crgtab[cr2]) >> (16)))];
            outptr[7] = range_limit[y2 + Cbbtab[cb2]];
            outptr[4] = 255;
        }
        outptr += 8;
    }
}
