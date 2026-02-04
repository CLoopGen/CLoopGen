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
    // Variant 2: Strided memory access (process every 2nd element, then fill backwards)
    JDIMENSION i;
    JSAMPROW out = outptr;
    for (i = 0; i < num_cols; i += 2) {
        JDIMENSION idx = i;
        out[2] = inptr0[idx];
        out[1] = inptr1[idx];
        out[0] = inptr2[idx];
        out[3] = 255;
        if (i + 1 < num_cols) {
            JDIMENSION next_idx = i + 1;
            out[6] = inptr0[next_idx];
            out[5] = inptr1[next_idx];
            out[4] = inptr2[next_idx];
            out[7] = 255;
        }
        out += 8;
    }
    outptr = out;
}
