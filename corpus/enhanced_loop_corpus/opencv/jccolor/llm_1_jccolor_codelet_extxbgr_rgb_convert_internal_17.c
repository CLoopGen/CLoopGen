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
    if (num_cols > 0) {
        col = 0;
        for (; col < num_cols / 2; col++) {
            outptr0[col] = inptr[3];
            outptr1[col] = inptr[2];
            outptr2[col] = inptr[1];
            inptr += 4;
        }
        for (; col < num_cols; col++) {
            outptr0[col] = inptr[3];
            outptr1[col] = inptr[2];
            outptr2[col] = inptr[1];
            inptr += 4;
        }
    }
}
