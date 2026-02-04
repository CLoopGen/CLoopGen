#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JLONG *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION block_size = 4;
    JDIMENSION col_block, offset;
    for (col_block = 0; col_block < num_cols; col_block += block_size) {
        for (offset = 0; offset < block_size; offset++) {
            col = col_block + offset;
            if (col >= num_cols) break;
            r = (inptr[2]);
            g = (inptr[1]);
            b = (inptr[0]);
            inptr += 3;
            outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
        }
    }
}
