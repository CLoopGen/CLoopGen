#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (process every 2nd element, then fill in)
    JDIMENSION step = 2;
    JSAMPROW out = outptr;
    // First pass: process even indices
    for (col = 0; col < num_cols; col += step) {
        r = ((int)(inptr0[col]));
        g = ((int)(inptr1[col]));
        b = ((int)(inptr2[col]));
        out[0] = (JSAMPLE)((r + g - 128) & 255);
        out[1] = (JSAMPLE)g;
        out[2] = (JSAMPLE)((b + g - 128) & 255);
        out += 3;
    }
    // Second pass: process odd indices
    for (col = 1; col < num_cols; col += step) {
        r = ((int)(inptr0[col]));
        g = ((int)(inptr1[col]));
        b = ((int)(inptr2[col]));
        out[0] = (JSAMPLE)((r + g - 128) & 255);
        out[1] = (JSAMPLE)g;
        out[2] = (JSAMPLE)((b + g - 128) & 255);
        out += 3;
    }
    outptr = out; // Update outptr to reflect total advancement
}
