#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW outptr_local = outptr;
    for (col = 0; col < num_cols; col++) {
        JSAMPLE temp0 = inptr0[col];
        JSAMPLE temp1 = inptr1[col];
        JSAMPLE temp2 = inptr2[col];
        outptr_local[0] = temp2;
        outptr_local[1] = temp1;
        outptr_local[2] = temp0;
        outptr_local += 3;
    }
    outptr = outptr_local;
}
