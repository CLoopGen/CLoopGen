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
    JDIMENSION step = 1;
    for (col = 0; col < num_cols; col += step) {
        JSAMPLE val0 = inptr0[col];
        JSAMPLE val1 = inptr1[col];
        JSAMPLE val2 = inptr2[col];
        JSAMPLE alpha = (val0 + val1 + val2) / 3 + 100; // Increased arithmetic intensity
        alpha = (alpha > 255) ? 255 : alpha;
        outptr[0] = alpha;
        outptr[1] = val2;
        outptr[2] = val1;
        outptr[3] = val0;
        outptr += 4;
    }
}
