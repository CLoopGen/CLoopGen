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
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION stride = 4;
    JDIMENSION total_elements = num_cols * 4;
    for (col = 0; col < total_elements; col += stride) {
        JDIMENSION base_col = col / stride;
        outptr0[base_col] = inptr[col + 0];
        outptr1[base_col] = inptr[col + 1];
        outptr2[base_col] = inptr[col + 2];
        outptr3[base_col] = inptr[col + 3];
    }
}
