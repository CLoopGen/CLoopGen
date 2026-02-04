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
    JDIMENSION col3;
    for (col = 0; col < num_cols; col++) {
        col3 = col * 3;
        outptr[col3 + 0] = inptr[col];
        outptr[col3 + 1] = inptr[col];
        outptr[col3 + 2] = inptr[col];
    }
}
