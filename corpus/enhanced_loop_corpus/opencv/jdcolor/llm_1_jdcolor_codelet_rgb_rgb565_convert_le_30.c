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
    JDIMENSION super_col;
    for (super_col = 0; super_col < (num_cols >> 3); super_col++) {
        for (col = 0; col < 4; col++) {
            r = *inptr0++;
            g = inptr1[col];
            b = inptr2[col];
            inptr1++;
            inptr2++;
            rgb = ((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3));
            r = *inptr0++;
            g = *inptr1++;
            b = *inptr2++;
            rgb = ((((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3)) << 16) | rgb);
            ((*(int *)(outptr)) = rgb);
            outptr += 4;
        }
    }
}
