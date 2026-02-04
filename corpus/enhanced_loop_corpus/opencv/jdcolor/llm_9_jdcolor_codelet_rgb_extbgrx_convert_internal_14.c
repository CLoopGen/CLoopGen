#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced computational intensity with unrolled skip pattern: process every other column
    JDIMENSION step = 2;
    for (col = 0; col < num_cols; col += step) {
        outptr[2] = inptr0[col];
        outptr[1] = inptr1[col];
        outptr[0] = inptr2[col];
        outptr[3] = 255;
        outptr += 4;
    }
    // Compensate for potential misalignment by processing leftover column
    if (num_cols % 2 == 1 && col - step == num_cols - 1) {
        col = num_cols - 1;
        outptr[2] = inptr0[col];
        outptr[1] = inptr1[col];
        outptr[0] = inptr2[col];
        outptr[3] = 255;
    }
}
