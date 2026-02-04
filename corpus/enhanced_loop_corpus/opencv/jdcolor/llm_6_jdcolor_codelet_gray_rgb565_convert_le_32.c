#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JLONG rgb;
extern unsigned int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION col;
    JSAMPROW inptr_local = inptr;
    JSAMPROW outptr_local = outptr;
    for (col = 0; col < (num_cols >> 1); col++) {
        JLONG rgb_low, rgb_high;
        unsigned int g1 = *inptr_local++;
        unsigned int g2 = *inptr_local++;
        rgb_low = ((((g1) << 8) & 63488) | (((g1) << 3) & 2016) | ((g1) >> 3));
        rgb_high = ((((g2) << 8) & 63488) | (((g2) << 3) & 2016) | ((g2) >> 3));
        rgb = ((rgb_high << 16) | rgb_low);
        (*(int *)(outptr_local)) = rgb;
        outptr_local += 4;
    }
    inptr = inptr_local;
    outptr = outptr_local;
}
