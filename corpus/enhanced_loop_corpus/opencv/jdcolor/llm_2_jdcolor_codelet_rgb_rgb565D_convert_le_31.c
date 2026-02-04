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
extern JSAMPLE *range_limit;
extern JDIMENSION num_cols;
extern JLONG d0;
extern JLONG rgb;
extern unsigned int r;
extern unsigned int g;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride-2 reading
    // Instead of incrementing pointers inside complex expressions, pre-calculate indices and access consecutively
    for (col = 0; col < (num_cols >> 1); col++) {
        JDIMENSION idx0_1 = inptr0[col * 2 + 0];
        JDIMENSION idx1_1 = inptr1[col * 2 + 0];
        JDIMENSION idx2_1 = inptr2[col * 2 + 0];
        r = range_limit[idx0_1 + ((d0) & 255)];
        g = range_limit[idx1_1 + (((d0) & 255) >> 1)];
        b = range_limit[idx2_1 + ((d0) & 255)];
        d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
        rgb = ((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3));

        JDIMENSION idx0_2 = inptr0[col * 2 + 1];
        JDIMENSION idx1_2 = inptr1[col * 2 + 1];
        JDIMENSION idx2_2 = inptr2[col * 2 + 1];
        r = range_limit[idx0_2 + ((d0) & 255)];
        g = range_limit[idx1_2 + (((d0) & 255) >> 1)];
        b = range_limit[idx2_2 + ((d0) & 255)];
        d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
        rgb = ((((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3)) << 16) | rgb);
        ((*(int *)(outptr + col * 4)) = rgb);
    }
}
