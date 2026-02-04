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
    for (col = 0; col < (num_cols >> 1); col++) {
        for (unsigned int unroll_factor = 0; unroll_factor < 2; unroll_factor++) {
            r = range_limit[((*inptr0++) + ((d0) & 255))];
            g = range_limit[((*inptr1++) + (((d0) & 255) >> 1))];
            b = range_limit[((*inptr2++) + ((d0) & 255))];
            d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
            rgb = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
            if (unroll_factor == 0) {
                continue;
            }
            rgb = ((rgb << 16) | (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936)));
            (*(int *)(outptr)) = rgb;
            outptr += 4;
        }
    }
}
