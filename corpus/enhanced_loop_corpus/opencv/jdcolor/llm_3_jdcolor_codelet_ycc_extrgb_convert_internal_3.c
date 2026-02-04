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
    // Variant 2: Strided memory access - process every 2nd column (unrolled-like pattern with stride)
    JDIMENSION col8;
    const JDIMENSION stride = 2;
    JSAMPROW out = outptr;
    
    for (col8 = 0; col8 < num_cols; col8 += stride) {
        // Process two elements per iteration with stride
        JDIMENSION idx1 = col8;
        JDIMENSION idx2 = col8 + 1;

        if (idx1 < num_cols) {
            y = inptr0[idx1];
            cb = inptr1[idx1];
            cr = inptr2[idx1];
            out[0] = range_limit[y + Crrtab[cr]];
            out[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
            out[2] = range_limit[y + Cbbtab[cb]];
            out += 3;
        }

        if (idx2 < num_cols) {
            y = inptr0[idx2];
            cb = inptr1[idx2];
            cr = inptr2[idx2];
            out[0] = range_limit[y + Crrtab[cr]];
            out[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
            out[2] = range_limit[y + Cbbtab[cb]];
            out += 3;
        }
    }
    outptr = out; // update global pointer
}
