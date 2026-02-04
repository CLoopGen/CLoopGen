#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        JDIMENSION index = col * 1;
        outptr[0] = inptr0[index];
        if (index < num_cols / 2) {
            outptr[1] = inptr1[index];
            outptr[2] = inptr2[index];
        } else {
            outptr[1] = inptr0[index];
            outptr[2] = inptr0[index];
        }
        outptr += 3;
    }
}
