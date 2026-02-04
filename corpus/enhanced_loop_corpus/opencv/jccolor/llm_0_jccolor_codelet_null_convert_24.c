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
    JDIMENSION col1, col2;
    for (col1 = 0; col1 < num_cols; col1++) {
        outptr0[col1] = *inptr++;
        for (col2 = 0; col2 < 1; col2++) {
            outptr1[col1] = *inptr++;
            outptr2[col1] = *inptr++;
        }
    }
}
