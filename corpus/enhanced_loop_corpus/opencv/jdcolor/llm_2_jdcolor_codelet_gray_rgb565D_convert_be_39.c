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
extern JSAMPLE *range_limit;
extern JDIMENSION num_cols;
extern JLONG d0;
extern JLONG rgb;
extern unsigned int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (col = 0; col < (num_cols >> 1); col++) {
    JDIMENSION idx1 = col * 2;
    JDIMENSION idx2 = col * 2 + 1;
    g = inptr[idx1];
    g = range_limit[((g) + ((d0) & 255))];
    rgb = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
    d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
    g = inptr[idx2];
    g = range_limit[((g) + ((d0) & 255))];
    rgb = ((rgb << 16) | (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936)));
    d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
    ((*(int *)(outptr)) = rgb);
    outptr += 4;
}
}
