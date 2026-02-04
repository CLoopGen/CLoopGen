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
    JDIMENSION i, j;
    for (i = 0; i < num_cols; i += 4) {
        for (j = 0; j < 4 && (i + j) < num_cols; j++) {
            *outptr++ = inptr0[i + j];
            *outptr++ = inptr1[i + j];
            *outptr++ = inptr2[i + j];
            *outptr++ = inptr3[i + j];
        }
    }
}
