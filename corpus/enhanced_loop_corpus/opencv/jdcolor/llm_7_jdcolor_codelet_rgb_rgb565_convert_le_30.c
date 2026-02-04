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
    JDIMENSION col;
    unsigned int temp_r, temp_g, temp_b;
    JLONG accumulated_rgb = 0;
    for (col = 0; col < (num_cols >> 1); col++) {
        temp_r = *inptr0++;
        temp_g = *inptr1++;
        temp_b = *inptr2++;
        accumulated_rgb = (((temp_r << 8) & 63488) | ((temp_g << 3) & 2016) | (temp_b >> 3));

        temp_r = *inptr0++;
        temp_g = *inptr1++;
        temp_b = *inptr2++;
        accumulated_rgb |= (((temp_r << 8) & 63488) | ((temp_g << 3) & 2016) | (temp_b >> 3)) << 16;

        *((int *)outptr) = accumulated_rgb;
        outptr += 4;
    }
}
