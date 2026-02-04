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
        r = (inptr[0]);
        g = (inptr[1]);
        b = (inptr[2]);
        inptr += 4;

        JLONG val_r = ctab[r + 0];
        JLONG val_g = ctab[g + (1 * (256))];
        JLONG val_b = ctab[b + (2 * (256))];
        JLONG sum = val_r + val_g + val_b;
        JLONG avg = (sum >> 16) / 3;
        JLONG weighted = (val_r + 2 * val_g + val_b) >> 16;
        outptr[col] = (JSAMPLE)((weighted + avg) >> 1);
    }
}
