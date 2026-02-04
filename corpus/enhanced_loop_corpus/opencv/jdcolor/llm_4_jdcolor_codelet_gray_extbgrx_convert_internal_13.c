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
        JSAMPLE val = inptr[col];
        if (val > 127) {
            outptr[0] = val;
            outptr[1] = val;
            outptr[2] = val;
        } else {
            outptr[0] = 0;
            outptr[1] = 0;
            outptr[2] = 0;
        }
        outptr[3] = 255;
        outptr += 4;
    }
}
