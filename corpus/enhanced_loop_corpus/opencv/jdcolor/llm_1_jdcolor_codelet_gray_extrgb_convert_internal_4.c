#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION block_size = 4;
    JDIMENSION remainder = num_cols % block_size;
    JDIMENSION i, col_block;

    // Process main blocks of 4 columns
    for (col_block = 0; col_block < num_cols - remainder; col_block += block_size) {
        for (i = 0; i < block_size; i++) {
            JDIMENSION c = col_block + i;
            outptr[0] = outptr[1] = outptr[2] = inptr[c];
            outptr += 3;
        }
    }

    // Handle remaining columns
    for (col = num_cols - remainder; col < num_cols; col++) {
        outptr[0] = outptr[1] = outptr[2] = inptr[col];
        outptr += 3;
    }
}
