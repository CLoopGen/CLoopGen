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
    JDIMENSION col4;
    for (col = 0; col < num_cols; col++) {
        col4 = col * 4;
        outptr[col4 + 1] = inptr0[col];
        outptr[col4 + 2] = inptr1[col];
        outptr[col4 + 3] = inptr2[col];
        outptr[col4] = 255;
    }
}
