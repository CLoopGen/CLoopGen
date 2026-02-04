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
    // Variant 1: Consecutive memory access with pre-increment and local accumulation
    JDIMENSION col_step;
    JSAMPROW in0 = inptr0;
    JSAMPROW in1 = inptr1;
    JSAMPROW in2 = inptr2;
    JSAMPROW out = outptr;
    JLONG d_temp = d0;

    for (col = 0; col < (num_cols >> 1); col++) {
        col_step = col << 1;

        // Load two sets of data using consecutive indexing instead of pointer increment
        r = range_limit[(in0[col_step] + ((d_temp) & 255))];
        g = range_limit[(in1[col_step] + (((d_temp) & 255) >> 1))];
        b = range_limit[(in2[col_step] + ((d_temp) & 255))];

        d_temp = ((((d_temp) & 255) << 24) | (((d_temp) >> 8) & 16777215));

        rgb = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));

        r = range_limit[(in0[col_step + 1] + ((d_temp) & 255))];
        g = range_limit[(in1[col_step + 1] + (((d_temp) & 255) >> 1))];
        b = range_limit[(in2[col_step + 1] + ((d_temp) & 255))];

        d_temp = ((((d_temp) & 255) << 24) | (((d_temp) >> 8) & 16777215));

        rgb = ((rgb << 16) | (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936)));

        *((int *)(out + (col << 2))) = rgb;
    }

    // Update global pointers only at the end to maintain external consistency
    inptr0 += num_cols;
    inptr1 += num_cols;
    inptr2 += num_cols;
    outptr += (num_cols << 1);
    d0 = d_temp;
}
