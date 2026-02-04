#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (num_cols > 0) {
        JDIMENSION unroll_factor = 4;
        JDIMENSION remainder = num_cols % unroll_factor;
        JDIMENSION col;

        for (col = 0; col < remainder; col++) {
            outptr0[col] = inptr[0];
            outptr1[col] = inptr[1];
            outptr2[col] = inptr[2];
            inptr += 3;
        }

        for (; col + (unroll_factor - 1) < num_cols; col += unroll_factor) {
            outptr0[col] = inptr[0];     outptr1[col] = inptr[1];     outptr2[col] = inptr[2];
            outptr0[col+1] = inptr[3];   outptr1[col+1] = inptr[4];   outptr2[col+1] = inptr[5];
            outptr0[col+2] = inptr[6];   outptr1[col+2] = inptr[7];   outptr2[col+2] = inptr[8];
            outptr0[col+3] = inptr[9];   outptr1[col+3] = inptr[10];  outptr2[col+3] = inptr[11];
            inptr += 3 * unroll_factor;
        }
    }
}
