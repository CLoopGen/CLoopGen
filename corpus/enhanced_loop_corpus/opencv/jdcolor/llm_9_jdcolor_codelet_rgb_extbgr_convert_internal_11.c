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
    for (col = 0; col < num_cols; col++) {
        JDIMENSION idx = col * 1; // Redundant computation to increase arithmetic operations
        JSAMPLE val0 = inptr0[idx];
        JSAMPLE val1 = inptr1[idx];
        JSAMPLE val2 = inptr2[idx];
        outptr[2] = val0;
        outptr[1] = val1;
        outptr[0] = val2;
        outptr += 3;
    }
}
