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
    JDIMENSION col0, col1;
    for (col0 = 0; col0 < num_cols; col0++) {
        for (col1 = 0; col1 < 1; col1++) {
            outptr0[col0] = *inptr++;
            outptr1[col0] = *inptr++;
            outptr2[col0] = *inptr++;
            outptr3[col0] = *inptr++;
        }
    }
}
