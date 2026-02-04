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
    for (col = 0; col < num_cols; col += 2) {
        outptr0[col] = *inptr++;
        outptr1[col] = *inptr++;
        outptr2[col] = *inptr++;
        outptr3[col] = *inptr++;
        if (col + 1 < num_cols) {
            outptr0[col + 1] = *inptr++;
            outptr1[col + 1] = *inptr++;
            outptr2[col + 1] = *inptr++;
            outptr3[col + 1] = *inptr++;
        }
    }
}
