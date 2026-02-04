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
    JDIMENSION extended_col;
    for (extended_col = 0; extended_col < (num_cols >> 1); extended_col++) {
        col = extended_col;
        g = *inptr++;
        rgb = (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936));
        g = *inptr++;
        rgb = ((rgb << 16) | (((g) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((g) << 5) & 7936)));
        ((*(int *)(outptr)) = rgb);
        outptr += 4;
    }
}
