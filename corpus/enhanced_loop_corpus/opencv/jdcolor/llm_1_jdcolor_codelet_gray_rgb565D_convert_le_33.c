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
    if (num_cols > 0) {
        col = 0;
        for (; col < (num_cols >> 1); ) {
            JDIMENSION unroll_count = (num_cols >> 1) - col >= 2 ? 2 : 1;
            for (JDIMENSION u = 0; u < unroll_count; u++) {
                g = *inptr++;
                g = range_limit[((g) + ((d0) & 255))];
                rgb = ((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3));
                d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
                g = *inptr++;
                g = range_limit[((g) + ((d0) & 255))];
                rgb = ((((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3)) << 16) | rgb);
                d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
                ((*(int *)(outptr)) = rgb);
                outptr += 4;
                col++;
            }
        }
    }
}
