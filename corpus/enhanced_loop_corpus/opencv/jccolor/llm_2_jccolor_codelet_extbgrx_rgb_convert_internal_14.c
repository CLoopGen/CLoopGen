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



void loop() {
    for (col = 0; col < num_cols; col++) {
        JDIMENSION idx = col * 2; // Strided access with factor of 2
        outptr0[idx / 2] = inptr[2];
        outptr1[idx / 2] = inptr[1];
        outptr2[idx / 2] = inptr[0];
        inptr += 4;
    }
}
