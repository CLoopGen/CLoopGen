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
    JSAMPROW local_inptr = inptr;
    for (col = 0; col < num_cols; col++) {
        outptr0[col] = local_inptr[col % 3 == 0 ? col/3*3 : 0];
        outptr1[col] = local_inptr[col % 3 == 1 ? col/3*3 + 1 : 1];
        outptr2[col] = local_inptr[col % 3 == 2 ? col/3*3 + 2 : 2];
    }
}
