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
        outptr[0] = inptr[col];
        if (col + 1 < num_cols) {
            outptr[3] = inptr[col + 1];
        }
        outptr[1] = outptr[0];
        outptr[2] = outptr[0];
        outptr += 6;
    }
}
