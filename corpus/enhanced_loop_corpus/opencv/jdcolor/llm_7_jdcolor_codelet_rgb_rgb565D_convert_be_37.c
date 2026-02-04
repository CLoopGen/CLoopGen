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
JLONG local_d0 = d0;
for (col = 0; col < (num_cols >> 1); col++) {
    r = range_limit[((*inptr0++) + (local_d0 & 255))];
    g = range_limit[((*inptr1++) + ((local_d0 & 255) >> 1))];
    b = range_limit[((*inptr2++) + (local_d0 & 255))];
    local_d0 = (((local_d0 & 255) << 24) | ((local_d0 >> 8) & 16777215));
    JLONG rgb_lo = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));

    r = range_limit[((*inptr0++) + (local_d0 & 255))];
    g = range_limit[((*inptr1++) + ((local_d0 & 255) >> 1))];
    b = range_limit[((*inptr2++) + (local_d0 & 255))];
    local_d0 = (((local_d0 & 255) << 24) | ((local_d0 >> 8) & 16777215));
    JLONG rgb_hi = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
    
    rgb = (rgb_hi << 16) | rgb_lo;
    (*(int *)(outptr)) = rgb;
    outptr += 4;
}
d0 = local_d0;
}
