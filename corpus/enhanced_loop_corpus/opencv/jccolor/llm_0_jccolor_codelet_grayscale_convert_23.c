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
extern int instride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION col_outer;
    for (col_outer = 0; col_outer < num_cols; col_outer++) {
        for (col = col_outer; col < col_outer + 1 && col < num_cols; col++) {
            outptr[col] = inptr[0];
            inptr += instride;
        }
    }
}
