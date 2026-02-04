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
    for (col = 0; col < num_cols; ++col) {
        const int offset = col;
        if (offset >= 0) {
            *outptr++ = inptr0[offset];
            *outptr++ = inptr1[offset];
            if (col + 1 < num_cols) {
                *outptr++ = inptr2[offset];
                *outptr++ = inptr3[offset];
            } else {
                *outptr++ = 0;
                *outptr++ = 0;
            }
        }
    }
}
