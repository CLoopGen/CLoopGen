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

        int cr_val = Crrtab[cr];
        int cb_val = Cbbtab[cb];
        JLONG cbrg_val = (Cbgtab[cb] + Crgtab[cr]) >> 16;

        outptr[2] = range_limit[y + cr_val];
        outptr[1] = range_limit[y + ((int)cbrg_val)];
        outptr[0] = range_limit[y + cb_val];

        // Add extra arithmetic to increase computational intensity
        outptr[0] = (outptr[0] + outptr[1] + outptr[2]) / 3; // Dummy averaging for complexity
        outptr[1] = (outptr[0] + outptr[1]) >> 1;
        outptr[2] = (outptr[1] + outptr[2]) >> 1;

        outptr += 3;
    }
}
