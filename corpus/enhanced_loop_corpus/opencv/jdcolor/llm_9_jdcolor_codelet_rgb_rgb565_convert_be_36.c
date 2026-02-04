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
for (col = 0; col < (num_cols >> 2); col++) {
    r = *inptr0++; g = *inptr1++; b = *inptr2++;
    JLONG rgb1 = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
    r = *inptr0++; g = *inptr1++; b = *inptr2++;
    JLONG rgb2 = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
    r = *inptr0++; g = *inptr1++; b = *inptr2++;
    JLONG rgb3 = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
    r = *inptr0++; g = *inptr1++; b = *inptr2++;
    JLONG rgb4 = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
    
    ((*(int *)(outptr)) = rgb1);
    outptr += 4;
    ((*(int *)(outptr)) = rgb2);
    outptr += 4;
    ((*(int *)(outptr)) = rgb3);
    outptr += 4;
    ((*(int *)(outptr)) = rgb4);
    outptr += 4;
}
}
