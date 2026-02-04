#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern int instride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW temp_inptr = inptr;
    for (col = 0; col < num_cols; col++) {
        outptr[num_cols - 1 - col] = temp_inptr[0];
        temp_inptr += instride;
    }
}
