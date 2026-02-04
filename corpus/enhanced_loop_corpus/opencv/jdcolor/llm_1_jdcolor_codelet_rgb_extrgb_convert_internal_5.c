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
    if (num_cols > 0) {
        col = 0;
        for (; col < num_cols - 2; ) {
            for (JDIMENSION step = 0; step < 3; step++, col++) {
                outptr[0] = inptr0[col];
                outptr[1] = inptr1[col];
                outptr[2] = inptr2[col];
                outptr += 3;
            }
        }
        for (; col < num_cols; col++) {
            outptr[0] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[2] = inptr2[col];
            outptr += 3;
        }
    } else {
        for (col = 0; col < num_cols; col++) {
            outptr[0] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[2] = inptr2[col];
            outptr += 3;
        }
    }
}
