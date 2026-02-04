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
    // Variant 1: Consecutive memory access with local array caching to improve spatial locality
    JSAMPLE local_inptr[4][num_cols];
    int local_y, local_cb, local_cr;
    JSAMPROW out = outptr;
    
    // Prefetch input data into local arrays (simulating cache-friendly access)
    for (col = 0; col < num_cols; col++) {
        local_inptr[0][col] = inptr0[col];
        local_inptr[1][col] = inptr1[col];
        local_inptr[2][col] = inptr2[col];
        local_inptr[3][col] = inptr3[col];
    }

    for (col = 0; col < num_cols; col++) {
        local_y = local_inptr[0][col];
        local_cb = local_inptr[1][col];
        local_cr = local_inptr[2][col];
        out[0] = range_limit[255 - (local_y + Crrtab[local_cr])];
        out[1] = range_limit[255 - (local_y + ((int)((Cbgtab[local_cb] + Crgtab[local_cr]) >> 16)))];
        out[2] = range_limit[255 - (local_y + Cbbtab[local_cb])];
        out[3] = local_inptr[3][col];
        out += 4;
    }
}
