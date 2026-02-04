#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            outptr[0] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[2] = inptr2[col];
            outptr[3] = inptr0[col + 1];
            outptr[4] = inptr1[col + 1];
            outptr[5] = inptr2[col + 1];
            outptr += 6;
        } else {
            outptr[0] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[2] = inptr2[col];
            outptr += 3;
        }
    }
}
