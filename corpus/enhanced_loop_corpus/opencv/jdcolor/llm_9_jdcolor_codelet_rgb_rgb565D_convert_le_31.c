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
for (col = 0; col < (num_cols >> 2); col++) {
    for (unsigned int unroll_factor = 0; unroll_factor < 4; unroll_factor++) {
        r = range_limit[((*inptr0++) + ((d0) & 255))];
        g = range_limit[(*inptr1++ + ((d0) & 255)/2)];
        b = range_limit[(*inptr2++ + ((d0) & 255))];
        d0 = (d0 & 255) << 24 | (d0 >> 8) & 0xFFFFFF;
        rgb = (r << 8 & 63488) | (g << 3 & 2016) | (b >> 3);
        *(int*)outptr = rgb;
        outptr += 4;
    }
}
}
