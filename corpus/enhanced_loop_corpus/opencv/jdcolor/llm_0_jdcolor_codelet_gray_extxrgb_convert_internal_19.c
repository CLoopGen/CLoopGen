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
    JDIMENSION col_outer, col_inner;
    for (col_outer = 0; col_outer < num_cols; col_outer += 2) {
        for (col_inner = 0; col_inner < 2 && (col_outer + col_inner) < num_cols; col_inner++) {
            col = col_outer + col_inner;
            outptr[1] = outptr[2] = outptr[3] = inptr[col];
            outptr[0] = 255;
            outptr += 4;
        }
    }
}
