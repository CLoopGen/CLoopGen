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
    JDIMENSION i;
    if (num_cols > 0) {
        for (i = 0; i < num_cols; i++) {
            JSAMPROW row0 = &inptr0[i];
            JSAMPROW row1 = &inptr1[i];
            JSAMPROW row2 = &inptr2[i];
            JSAMPROW row3 = &inptr3[i];
            *outptr++ = *row0;
            *outptr++ = *row1;
            *outptr++ = *row2;
            *outptr++ = *row3;
        }
    }
}
