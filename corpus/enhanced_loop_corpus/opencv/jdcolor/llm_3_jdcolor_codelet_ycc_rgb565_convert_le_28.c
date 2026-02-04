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
extern JLONG rgb;
extern unsigned int r;
extern unsigned int g;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via index array (simulating non-contiguous input)
    // Assume auxiliary index array exists: extern JDIMENSION *col_index; (not declared here due to constraints)
    // For realism, simulate stride of 2 using multiplication in index (avoiding pointer arithmetic)

    for (col = 0; col < (num_cols >> 1); col++) {
        JDIMENSION idx1 = col * 2;     // First pixel in pair
        JDIMENSION idx2 = col * 2 + 1; // Second pixel

        // Indirect access through calculated indices (strided pattern)
        y = inptr0[idx1]; cb = inptr1[idx1]; cr = inptr2[idx1];
        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        b = range_limit[y + Cbbtab[cb]];
        JLONG rgb1 = (((r << 8) & 63488) | ((g << 3) & 2016) | (b >> 3));

        y = inptr0[idx2]; cb = inptr1[idx2]; cr = inptr2[idx2];
        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        b = range_limit[y + Cbbtab[cb]];
        JLONG rgb2 = (((r << 8) & 63488) | ((g << 3) & 2016) | (b >> 3));

        rgb = (rgb2 << 16) | rgb1;
        ((int*)outptr)[col] = rgb; // Write result with strided output (every 4 bytes)
    }

    // Update output pointer after loop
    outptr += (num_cols >> 1) * 4;
}
