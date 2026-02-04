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
    JDIMENSION col_outer, col_inner;
    JDIMENSION half_cols = (num_cols + 1) / 2;
    for (col_outer = 0; col_outer < half_cols; col_outer++) {
        for (col_inner = 0; col_inner < 2; col_inner++) {
            col = col_outer * 2 + col_inner;
            if (col >= num_cols) break;
            outptr0[col] = inptr[2];
            outptr1[col] = inptr[1];
            outptr2[col] = inptr[0];
            inptr += 3;
        }
    }
}
