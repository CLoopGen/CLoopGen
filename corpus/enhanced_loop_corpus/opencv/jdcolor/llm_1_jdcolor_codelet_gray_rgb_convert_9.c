#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (num_cols > 0) {
        JDIMENSION group, remainder;
        JDIMENSION unroll_factor = 4;
        JDIMENSION aligned_cols = (num_cols / unroll_factor) * unroll_factor;

        col = 0;
        for (group = 0; group < aligned_cols; group += unroll_factor) {
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr += 3; col++;
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr += 3; col++;
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr += 3; col++;
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr += 3; col++;
        }
        for (; col < num_cols; col++) {
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr += 3;
        }
    }
}
