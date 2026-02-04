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
for (col = 0; col < (num_cols >> 1); col++) {
    r = *inptr0++;
    g = *inptr1++;
    b = *inptr2++;
    rgb = ((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3));
    
    if (col % 2 == 0) {
        r = *inptr0++;
        g = *inptr1++;
        b = *inptr2++;
        rgb = ((((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3)) << 16) | rgb);
        (*(int *)(outptr)) = rgb;
        outptr += 4;
    } else {
        // Skip second read and pack only first RGB pair
        rgb <<= 16;
        (*(int *)(outptr)) = rgb;
        outptr += 4;
        inptr0--; inptr1--; inptr2--; // Compensate for previous increment
    }
}
}
