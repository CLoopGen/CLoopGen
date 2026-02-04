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
    JDIMENSION row, col_block;
    for (row = 0; row < 1; row++) {
        for (col_block = 0; col_block < num_cols; col_block++) {
            col = col_block;
            outptr[0] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[2] = inptr2[col];
            outptr[3] = 255;
            outptr += 4;
        }
    }
}
