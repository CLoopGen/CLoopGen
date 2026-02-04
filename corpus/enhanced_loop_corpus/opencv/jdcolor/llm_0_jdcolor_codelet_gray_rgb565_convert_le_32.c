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
    JDIMENSION outer_col;
    for (outer_col = 0; outer_col < (num_cols >> 2); outer_col++) {
        for (col = 0; col < 2; col++) {
            g = *inptr++;
            rgb = ((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3));
            g = *inptr++;
            rgb = ((((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3)) << 16) | rgb);
            ((*(int *)(outptr)) = rgb);
            outptr += 4;
        }
    }
}
