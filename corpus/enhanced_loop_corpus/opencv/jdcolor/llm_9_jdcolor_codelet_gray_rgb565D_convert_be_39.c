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
for (col = 0; col < (num_cols >> 2); col++) {
    g = *inptr++;
    g = range_limit[((g) + ((d0) & 255))];
    rgb = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
    d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
    g = *inptr++;
    g = range_limit[((g) + ((d0) & 255))];
    rgb = ((rgb << 16) | (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936)));
    d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
    g = *inptr++;
    g = range_limit[((g) + ((d0) & 255))];
    rgb |= (((uint64_t)g & 248) | (g >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936)) << 32;
    d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
    g = *inptr++;
    g = range_limit[((g) + ((d0) & 255))];
    rgb |= (((uint64_t)g & 248) | (g >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936)) << 48;
    d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
    *(uint64_t*)(outptr) = rgb;
    outptr += 8;
}
}
