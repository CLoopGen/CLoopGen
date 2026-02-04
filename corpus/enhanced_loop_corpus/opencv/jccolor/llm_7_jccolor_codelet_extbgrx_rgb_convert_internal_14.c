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
        JSAMPLE temp0 = inptr[2];
        JSAMPLE temp1 = inptr[1];
        JSAMPLE temp2 = inptr[0];
        outptr0[col] = temp0;
        outptr1[col] = temp1;
        outptr2[col] = temp2;
        inptr += 4;
    }
}
