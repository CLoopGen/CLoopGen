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
    // Variant 1: Consecutive memory access with array base offset applied once
    JSAMPROW out = outptr;
    const JSAMPROW in0 = inptr0;
    const JSAMPROW in1 = inptr1;
    const JSAMPROW in2 = inptr2;
    for (col = 0; col < num_cols; col++) {
        y = in0[col];
        cb = in1[col];
        cr = in2[col];
        int crr = Crrtab[cr];
        int cbb = Cbbtab[cb];
        int crg = (int)((Crgtab[cr] + Cbgtab[cb]) >> 16);
        out[0] = range_limit[y + cbb];
        out[1] = range_limit[y + crg];
        out[2] = range_limit[y + crr];
        out[3] = 255;
        out += 4;
    }
    outptr = out; // Update original pointer if needed by caller
}
