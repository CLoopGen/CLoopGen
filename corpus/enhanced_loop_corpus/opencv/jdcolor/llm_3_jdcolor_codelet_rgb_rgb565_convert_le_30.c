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
    // Variant 2: Strided memory access - process every second element first, then the odd-offsets (structure of arrays split by parity)
    JSAMPROW p0 = inptr0;
    JSAMPROW p1 = inptr1;
    JSAMPROW p2 = inptr2;
    JSAMPROW out = outptr;

    // First pass: even indices
    for (col = 0; col < (num_cols >> 1); col++) {
        JDIMENSION idx = col * 2;
        r = p0[idx];
        g = p1[idx];
        b = p2[idx];
        JLONG rgb0 = (((r << 8) & 63488) | ((g << 3) & 2016) | (b >> 3));

        r = p0[idx + 1];
        g = p1[idx + 1];
        b = p2[idx + 1];
        JLONG rgb1 = (((r << 8) & 63488) | ((g << 3) & 2016) | (b >> 3));

        JLONG combined_rgb = (rgb1 << 16) | rgb0;
        *(int*)(out + (col << 2)) = combined_rgb;
    }

    // Update pointers to reflect advancement
    inptr0 += num_cols;
    inptr1 += num_cols;
    inptr2 += num_cols;
    outptr += (num_cols >> 1) * 4;
}
