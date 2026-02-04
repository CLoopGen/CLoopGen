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
    for (col_outer = 0; col_outer < num_cols; col_outer += 4) {
        for (col_inner = 0; col_inner < 4 && (col_outer + col_inner) < num_cols; col_inner++) {
            JDIMENSION idx = col_outer + col_inner;
            outptr0[idx] = inptr[0];
            outptr1[idx] = inptr[1];
            outptr2[idx] = inptr[2];
            inptr += 3;
        }
    }
}
