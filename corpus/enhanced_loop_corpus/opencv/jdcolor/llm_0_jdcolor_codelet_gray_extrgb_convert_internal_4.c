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
    JDIMENSION col1, col2;
    for (col1 = 0; col1 < num_cols; col1++) {
        for (col2 = 0; col2 < 1; col2++) { // Artificially nested with fixed inner iteration
            outptr[0] = inptr[col1];
            outptr[1] = inptr[col1];
            outptr[2] = inptr[col1];
            outptr += 3;
        }
    }
}
