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
    JDIMENSION outer_col;
    for (outer_col = 0; outer_col < num_cols; outer_col += stride) {
        JDIMENSION inner_col;
        for (inner_col = 0; inner_col < stride; inner_col++) {
            col = outer_col + inner_col;
            if (col >= num_cols) break;
            outptr[2] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[0] = inptr2[col];
            outptr += 3;
        }
    }
}
