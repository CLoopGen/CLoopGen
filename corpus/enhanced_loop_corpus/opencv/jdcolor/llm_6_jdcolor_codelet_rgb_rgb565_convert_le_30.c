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
    JDIMENSION col;
    unsigned int r0, g0, b0, r1, g1, b1;
    JLONG rgb_low, rgb_high;
    for (col = 0; col < (num_cols >> 1); col++) {
        r0 = *inptr0++;
        g0 = *inptr1++;
        b0 = *inptr2++;
        r1 = *inptr0++;
        g1 = *inptr1++;
        b1 = *inptr2++;

        rgb_low = (((r0 << 8) & 63488) | ((g0 << 3) & 2016) | (b0 >> 3));
        rgb_high = (((r1 << 8) & 63488) | ((g1 << 3) & 2016) | (b1 >> 3));

        rgb = (rgb_high << 16) | rgb_low;

        *((int *)outptr) = rgb;
        outptr += 4;
    }
}
