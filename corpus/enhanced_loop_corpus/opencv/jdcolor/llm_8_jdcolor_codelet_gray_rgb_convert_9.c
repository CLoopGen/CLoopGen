#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            outptr[0] = inptr[col];
            outptr[1] = inptr[col];
            outptr[2] = inptr[col];
            outptr[3] = inptr[col + 1];
            outptr[4] = inptr[col + 1];
            outptr[5] = inptr[col + 1];
            outptr += 6;
        } else {
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr += 3;
        }
    }
}
