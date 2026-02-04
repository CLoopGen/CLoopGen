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
    JDIMENSION stride = 4;
    JDIMENSION block_size = 16;
    JDIMENSION col_block, col_inner;

    for (col_block = 0; col_block < num_cols; col_block += block_size) {
        for (col_inner = 0; col_inner < block_size && (col_block + col_inner) < num_cols; col_inner++) {
            col = col_block + col_inner;
            outptr[3] = inptr0[col];
            outptr[2] = inptr1[col];
            outptr[1] = inptr2[col];
            outptr[0] = 255;
            outptr += 4;
        }
    }
}
