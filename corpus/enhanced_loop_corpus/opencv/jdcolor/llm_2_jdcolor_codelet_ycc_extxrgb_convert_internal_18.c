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
    // Variant 1: Consecutive memory access with local array caching to improve spatial locality
    JSAMPLE local_inptr0[4], local_inptr1[4], local_inptr2[4];
    JDIMENSION col_end = num_cols - (num_cols % 4);
    
    for (col = 0; col < col_end; col += 4) {
        // Load 4 consecutive elements into local arrays for better cache usage
        for (int i = 0; i < 4; i++) {
            local_inptr0[i] = inptr0[col + i];
            local_inptr1[i] = inptr1[col + i];
            local_inptr2[i] = inptr2[col + i];
        }
        
        // Process each of the 4 pixels using cached values
        for (int i = 0; i < 4; i++) {
            y = local_inptr0[i];
            cb = local_inptr1[i];
            cr = local_inptr2[i];
            outptr[1] = range_limit[y + Crrtab[cr]];
            outptr[2] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
            outptr[3] = range_limit[y + Cbbtab[cb]];
            outptr[0] = 255;
            outptr += 4;
        }
    }
    
    // Handle remaining columns
    for (; col < num_cols; col++) {
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
