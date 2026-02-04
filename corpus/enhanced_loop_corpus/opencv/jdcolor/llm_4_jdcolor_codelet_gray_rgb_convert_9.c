#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        JSAMPLE val = inptr[col];
        if (val > 0) {
            outptr[0] = val;
            outptr[1] = val;
            outptr[2] = val;
        } else {
            outptr[0] = outptr[1] = outptr[2] = 1;
        }
        outptr += 3;
    }
}
