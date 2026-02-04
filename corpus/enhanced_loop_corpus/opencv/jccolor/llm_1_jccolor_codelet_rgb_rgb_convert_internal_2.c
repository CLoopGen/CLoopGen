#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION stride = 3;
    JDIMENSION total_elements = num_cols * stride;
    JDIMENSION i;
    for (i = 0; i < total_elements; i += stride) {
        JDIMENSION col = i / stride;
        outptr0[col] = inptr[i + 0];
        outptr1[col] = inptr[i + 1];
        outptr2[col] = inptr[i + 2];
    }
}
