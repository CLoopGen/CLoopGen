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
    JDIMENSION col1, col2;
    for (col1 = 0; col1 < num_cols; col1 += 2) {
        for (col2 = 0; col2 < 2 && (col1 + col2) < num_cols; col2++) {
            JDIMENSION idx = col1 + col2;
            outptr[2] = inptr0[idx];
            outptr[1] = inptr1[idx];
            outptr[0] = inptr2[idx];
            outptr += 3;
        }
    }
}
