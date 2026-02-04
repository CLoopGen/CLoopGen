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
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            outptr0[col] = inptr[1];
            outptr1[col] = inptr[2];
            outptr2[col] = inptr[3];
            outptr0[col + 1] = inptr[5];
            outptr1[col + 1] = inptr[6];
            outptr2[col + 1] = inptr[7];
            inptr += 8;
        } else {
            outptr0[col] = inptr[1];
            outptr1[col] = inptr[2];
            outptr2[col] = inptr[3];
            inptr += 4;
        }
    }
}
