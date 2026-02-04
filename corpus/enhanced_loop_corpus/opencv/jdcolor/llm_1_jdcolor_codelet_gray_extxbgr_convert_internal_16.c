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
    JDIMENSION stride = 1;
    JDIMENSION block_size = 4;
    JDIMENSION total_blocks = (num_cols + block_size - 1) / block_size;
    for (JDIMENSION blk = 0; blk < total_blocks; blk++) {
        for (col = blk * block_size; col < (blk + 1) * block_size && col < num_cols; col++) {
            outptr[3] = outptr[2] = outptr[1] = inptr[col];
            outptr[0] = 255;
            outptr += 4;
        }
    }
}
