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
    // Variant 1: Consecutive memory access with pre-computed pointers and unrolled array lookups
    JSAMPROW in0 = inptr0;
    JSAMPROW in1 = inptr1;
    JSAMPROW in2 = inptr2;
    JSAMPROW out = outptr;
    JDIMENSION limit = num_cols >> 1;

    for (col = 0; col < limit; col++) {
        // Load two consecutive pixels at once using direct indexing
        y = in0[0]; cb = in1[0]; cr = in2[0];
        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        b = range_limit[y + Cbbtab[cb]];
        JLONG rgb1 = (((r << 8) & 63488) | ((g << 3) & 2016) | (b >> 3));

        y = in0[1]; cb = in1[1]; cr = in2[1];
        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        b = range_limit[y + Cbbtab[cb]];
        JLONG rgb2 = (((r << 8) & 63488) | ((g << 3) & 2016) | (b >> 3));

        rgb = (rgb2 << 16) | rgb1;
        *((int*)out) = rgb;

        // Advance all pointers by 2 for next iteration (strided by 2)
        in0 += 2;
        in1 += 2;
        in2 += 2;
        out += 4;
    }

    // Update global pointers
    inptr0 = in0;
    inptr1 = in1;
    inptr2 = in2;
    outptr = out;
}
