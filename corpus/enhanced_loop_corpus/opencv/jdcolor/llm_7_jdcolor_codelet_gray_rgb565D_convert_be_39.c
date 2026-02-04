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
JLONG local_d0 = d0;
for (col = 0; col < (num_cols >> 1); col++) {
    g = *inptr++;
    g = range_limit[((g) + (local_d0 & 255))];
    rgb = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
    local_d0 = (((local_d0 & 255) << 24) | ((local_d0 >> 8) & 16777215));

    g = *inptr++;
    g = range_limit[((g) + (local_d0 & 255))];
    rgb = ((rgb << 16) | (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936)));
    local_d0 = (((local_d0 & 255) << 24) | ((local_d0 >> 8) & 16777215));

    (*(int *)(outptr)) = rgb;
    outptr += 4;
}
d0 = local_d0;
}
