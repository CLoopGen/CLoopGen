#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JLONG *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        r = (inptr[2]) >> 4;
        g = (inptr[1]) >> 4;
        b = (inptr[0]) >> 4;
        inptr += 3;
        JLONG red_val   = ctab[r + 0];
        JLONG green_val = ctab[g + (1 * 256)];
        JLONG blue_val  = ctab[b + (2 * 256)];
        JLONG sum       = red_val + green_val + blue_val;
        outptr[col] = (JSAMPLE)((sum + 0x8000) >> 16); // Add rounding offset before shift
    }
}
