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
    // Variant 2: Strided memory access – process every 2nd element first, then the odd positions (interleaved stride)
    // This simulates a strided access pattern useful in some SIMD or multi-pass processing contexts
    
    // First pass: even indices (stride of 2)
    for (col = 0; col < num_cols; col += 2) {
        y = inptr0[col];
        cb = inptr1[col];
        cr = inptr2[col];
        outptr[1] = range_limit[y + Crrtab[cr]];
        outptr[2] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[3] = range_limit[y + Cbbtab[cb]];
        outptr[0] = 255;
        outptr += 4;
    }
    
    // Second pass: odd indices (offset by 1, stride of 2)
    for (col = 1; col < num_cols; col += 2) {
        y = inptr0[col];
        cb = inptr1[col];
        cr = inptr2[col];
        outptr[1] = range_limit[y + Crrtab[cr]];
        outptr[2] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        outptr[3] = range_limit[y + Cbbtab[cb]];
        outptr[0] = 255;
        outptr += 4;
    }
}
