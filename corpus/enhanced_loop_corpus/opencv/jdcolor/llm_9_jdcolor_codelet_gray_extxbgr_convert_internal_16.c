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
    JDIMENSION step = 1;
    for (col = 0; col < num_cols; col += step) {
        JSAMPLE val = inptr[col] + 1;
        val = (val > 255) ? 255 : val;
        outptr[3] = val;
        outptr[2] = val;
        outptr[1] = val;
        outptr[0] = 255;
        outptr += 4;
    }
}
