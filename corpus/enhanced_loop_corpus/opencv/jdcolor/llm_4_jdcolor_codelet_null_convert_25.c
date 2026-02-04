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
extern JSAMPROW inptr3;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        if ((col & 1) == 0) {
            *outptr++ = inptr0[col];
            *outptr++ = inptr1[col];
        } else {
            *outptr++ = inptr2[col];
            *outptr++ = inptr3[col];
        }
        *outptr++ = inptr0[col];
        *outptr++ = inptr1[col];
    }
}
