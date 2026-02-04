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
    JLONG temp_d0_first, temp_d0_second;
    JSAMPLE g1, g2;

    g1 = *inptr++;
    temp_d0_first = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
    g1 = range_limit[g1 + (d0 & 255)];
    
    g2 = *inptr++;
    temp_d0_second = ((((temp_d0_first) & 255) << 24) | ((temp_d0_first >> 8) & 16777215));
    g2 = range_limit[g2 + (temp_d0_first & 255)];

    rgb = (((g1) & 248) | ((g1) >> 5) | (((g1) << 11) & 57344) | (((g1) << 5) & 7936));
    rgb = (rgb << 16) | (((g2) & 248) | ((g2) >> 5) | (((g2) << 11) & 57344) | (((g2) << 5) & 7936));

    d0 = temp_d0_second;
    (*(int *)(outptr)) = rgb;
    outptr += 4;
}
}
