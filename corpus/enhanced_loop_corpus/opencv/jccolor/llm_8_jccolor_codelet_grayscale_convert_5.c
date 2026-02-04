#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION count;
extern int instride;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION i;
    for (i = 0; i < num_cols; i += 2) {
        *outptr++ = inptr[0];
        *outptr++ = inptr[instride];
        inptr += 2 * instride;
    }
    if (num_cols % 2 != 0) {
        *outptr++ = *inptr;
    }
}
