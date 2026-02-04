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
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            outptr[1] = outptr[2] = outptr[3] = inptr[col];
            outptr[0] = 255;
            outptr += 4;
            outptr[1] = outptr[2] = outptr[3] = inptr[col + 1];
            outptr[0] = 255;
            outptr += 4;
        } else {
            outptr[1] = outptr[2] = outptr[3] = inptr[col];
            outptr[0] = 255;
            outptr += 4;
        }
    }
}
