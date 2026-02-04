#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        outptr[0] = inptr[col];
        outptr[1] = inptr[col];
        outptr[2] = inptr[col];
        outptr[3] = 255;
        if (inptr[col] >= 128) {
            outptr[0] ^= 0xFF;
            outptr[1] ^= 0xFF;
            outptr[2] ^= 0xFF;
        }
        outptr += 4;
    }
}
