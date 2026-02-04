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
    JLONG temp_r, temp_g, temp_b;
    for (col = 0; col < num_cols; col++) {
        r = inptr[0];
        g = inptr[1];
        b = inptr[2];
        temp_r = ctab[r + 0];
        temp_g = ctab[g + (1 * (256))];
        temp_b = ctab[b + (2 * (256))];
        inptr += 3;
        outptr[col] = (JSAMPLE)((temp_r + temp_g + temp_b) >> 16);
    }
}
