#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JLONG rgb;
extern unsigned int r;
extern unsigned int g;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual pointer arithmetic unrolled by 2 elements
    JSAMPROW p0 = inptr0;
    JSAMPROW p1 = inptr1;
    JSAMPROW p2 = inptr2;
    JSAMPROW out = outptr;
    JDIMENSION limit = num_cols & ~1U;  // Ensure even number of columns

    for (col = 0; col < limit; col += 2) {
        unsigned int r0 = p0[0], g0 = p1[0], b0 = p2[0];
        unsigned int r1 = p0[1], g1 = p1[1], b1 = p2[1];
        JLONG rgb0 = (((r0 << 8) & 63488) | ((g0 << 3) & 2016) | (b0 >> 3));
        JLONG rgb1 = (((r1 << 8) & 63488) | ((g1 << 3) & 2016) | (b1 >> 3));
        JLONG combined_rgb = (rgb1 << 16) | rgb0;
        *(int*)out = combined_rgb;
        p0 += 2; p1 += 2; p2 += 2;
        out += 4;
    }

    inptr0 = p0;
    inptr1 = p1;
    inptr2 = p2;
    outptr = out;
}
