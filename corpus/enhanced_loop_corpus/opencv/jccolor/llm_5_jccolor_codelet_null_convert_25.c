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
    for (col = 0; col < num_cols; col++) {
        outptr0[col] = (col % 4 != 0) ? *inptr++ : 0;
        outptr1[col] = (col % 4 != 1) ? *inptr++ : 0;
        outptr2[col] = (col % 4 != 2) ? *inptr++ : 0;
        outptr3[col] = (col % 4 != 3) ? *inptr++ : 0;
    }
}
