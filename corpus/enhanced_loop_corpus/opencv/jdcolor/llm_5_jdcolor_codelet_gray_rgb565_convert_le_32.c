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
for (col = 0; col < (num_cols >> 1); col++) {
    g = *inptr++;
    rgb = ((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3));
    if (inptr < (inptr + num_cols - 2*col)) { // Simulated lookahead guard
        g = *inptr++;
        rgb = ((((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3)) << 16) | rgb);
    } else {
        rgb |= (rgb << 16); // Duplicate lower 16 bits if second byte not available
    }
    ((*(int *)(outptr)) = rgb);
    outptr += 4;
}
}
