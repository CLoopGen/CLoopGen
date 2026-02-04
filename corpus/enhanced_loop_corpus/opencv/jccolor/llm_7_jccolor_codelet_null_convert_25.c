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
    JSAMPROW local_inptr = inptr;
    for (col = 0; col < num_cols; col++) {
        outptr3[col] = local_inptr[3];
        outptr2[col] = local_inptr[2];
        outptr1[col] = local_inptr[1];
        outptr0[col] = local_inptr[0];
        local_inptr += 4;
    }
    inptr = local_inptr;
}
