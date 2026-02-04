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
    if (num_cols > 0) {
        col = 0;
        for (; col < num_cols - 1; ) {
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr[3] = 255;
            outptr += 4;
            col++;
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr[3] = 255;
            outptr += 4;
            col++;
        }
        if (col < num_cols) {
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr[3] = 255;
            outptr += 4;
        }
    } else {
        for (col = 0; col < num_cols; col++) {
            outptr[0] = outptr[1] = outptr[2] = inptr[col];
            outptr[3] = 255;
            outptr += 4;
        }
    }
}
