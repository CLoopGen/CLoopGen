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
    JDIMENSION col_outer;
    for (col_outer = 0; col_outer < num_cols; col_outer += 2) {
        for (col = col_outer; col < num_cols && col < col_outer + 2; col++) {
            outptr[0] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[2] = inptr2[col];
            outptr += 3;
        }
    }
}
