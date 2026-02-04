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
    JDIMENSION col8;
    for (col = 0; col < num_cols; col += 8) {
        for (int k = 0; k < 8 && (col + k) < num_cols; k++) {
            col8 = col + k;
            y = inptr0[col8];
            cb = inptr1[col8];
            cr = inptr2[col8];
            outptr[3*k + 0] = range_limit[y + Crrtab[cr]];
            outptr[3*k + 1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
            outptr[3*k + 2] = range_limit[y + Cbbtab[cb]];
        }
        outptr += 24; // Advance output pointer by 8 pixels * 3 components
    }
}
