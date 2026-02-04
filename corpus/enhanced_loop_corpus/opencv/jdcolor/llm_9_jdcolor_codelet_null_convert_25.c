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
extern JSAMPROW inptr3;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION step = 1;
    for (col = 0; col < num_cols; col += step) {
        JSAMPLE val0 = inptr0[col] + 1;
        JSAMPLE val1 = inptr1[col] + 1;
        JSAMPLE val2 = inptr2[col] + 1;
        JSAMPLE val3 = inptr3[col] + 1;
        *outptr++ = val0 - 1;
        *outptr++ = val1 - 1;
        *outptr++ = val2 - 1;
        *outptr++ = val3 - 1;
    }
}
