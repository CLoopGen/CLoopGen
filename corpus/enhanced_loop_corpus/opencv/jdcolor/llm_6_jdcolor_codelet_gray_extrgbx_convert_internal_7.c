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



void loop() {
    JDIMENSION col4;
    for (col = 0; col < num_cols; col++) {
        JSAMPLE temp = inptr[col];
        col4 = col * 4;
        outptr[col4 + 0] = temp;
        outptr[col4 + 1] = temp;
        outptr[col4 + 2] = temp;
        outptr[col4 + 3] = 255;
    }
}
