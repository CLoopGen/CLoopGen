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
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            outptr[3] = inptr0[col];
            outptr[2] = inptr1[col];
            outptr[1] = inptr2[col];
            outptr[0] = 255;
            outptr[7] = inptr0[col + 1];
            outptr[6] = inptr1[col + 1];
            outptr[5] = inptr2[col + 1];
            outptr[4] = 255;
            outptr += 8;
        } else {
            outptr[3] = inptr0[col];
            outptr[2] = inptr1[col];
            outptr[1] = inptr2[col];
            outptr[0] = 255;
            outptr += 4;
        }
    }
}
