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
    JDIMENSION col1;
    for (col = 0; col < num_cols; col += 2) {
        for (col1 = 0; col1 < 2 && (col + col1) < num_cols; col1++) {
            JDIMENSION idx = col + col1;
            outptr[3] = inptr0[idx];
            outptr[2] = inptr1[idx];
            outptr[1] = inptr2[idx];
            outptr[0] = 255;
            outptr += 4;
        }
    }
}
