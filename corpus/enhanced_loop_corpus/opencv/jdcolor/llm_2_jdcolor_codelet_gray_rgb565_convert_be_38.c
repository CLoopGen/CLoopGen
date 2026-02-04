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
    // Variant 1: Consecutive memory access with manual pointer arithmetic unrolling
    JDIMENSION col4 = (num_cols >> 1) & ~1;  // Ensure even count for safe unrolling
    JSAMPROW inptr_local = inptr;
    JSAMPROW outptr_local = outptr;

    for (col = 0; col < col4; col += 2) {
        // Process two iterations at once with consecutive reads
        JSAMPLE g1 = inptr_local[0];
        JSAMPLE g2 = inptr_local[1];
        JSAMPLE g3 = inptr_local[2];
        JSAMPLE g4 = inptr_local[3];

        JLONG rgb1 = (((g1) & 248) | ((g1) >> 5) | (((g1) << 11) & 57344) | (((g1) << 5) & 7936));
        rgb1 |= ((((JLONG)(((g2) & 248) | ((g2) >> 5) | (((g2) << 11) & 57344) | (((g2) << 5) & 7936))) << 16));

        JLONG rgb2 = (((g3) & 248) | ((g3) >> 5) | (((g3) << 11) & 57344) | (((g3) << 5) & 7936));
        rgb2 |= ((((JLONG)(((g4) & 248) | ((g4) >> 5) | (((g4) << 11) & 57344) | (((g4) << 5) & 7936))) << 16));

        *(int*)(outptr_local + 0) = rgb1;
        *(int*)(outptr_local + 4) = rgb2;

        inptr_local += 4;
        outptr_local += 8;
    }

    // Handle remaining element if original col count was odd
    for (; col < (num_cols >> 1); col++) {
        g = *inptr_local++;
        rgb = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
        g = *inptr_local++;
        rgb = ((rgb << 16) | (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936)));
        (*(int *)(outptr_local)) = rgb;
        outptr_local += 4;
    }

    inptr = inptr_local;
    outptr = outptr_local;
}
