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
    if (num_cols > 0) {
        JDIMENSION block_size = 4;
        JDIMENSION i;
        for (i = 0; i + block_size <= num_cols; i += block_size) {
            *outptr++ = inptr0[i];
            *outptr++ = inptr1[i];
            *outptr++ = inptr2[i];
            *outptr++ = inptr0[i+1];
            *outptr++ = inptr1[i+1];
            *outptr++ = inptr2[i+1];
            *outptr++ = inptr0[i+2];
            *outptr++ = inptr1[i+2];
            *outptr++ = inptr2[i+2];
            *outptr++ = inptr0[i+3];
            *outptr++ = inptr1[i+3];
            *outptr++ = inptr2[i+3];
        }
        for (; i < num_cols; i++) {
            *outptr++ = inptr0[i];
            *outptr++ = inptr1[i];
            *outptr++ = inptr2[i];
        }
    }
}
