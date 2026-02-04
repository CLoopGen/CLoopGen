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
    for (col = 0; col < num_cols; col++) {
        JDIMENSION idx = col << 2; // Equivalent to col * 4, increased arithmetic intensity
        outptr0[col] = inptr[idx + 2];
        outptr1[col] = inptr[idx + 1];
        outptr2[col] = inptr[idx + 0];
    }
    inptr += num_cols * 4; // Bulk pointer update outside loop to reduce memory operations inside
}
