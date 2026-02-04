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



void loop() {
    JSAMPROW temp_inptr = inptr + 1;
    for (col = 0; col < num_cols; col++) {
        r = temp_inptr[col * 4];
        g = temp_inptr[col * 4 + 1];
        b = temp_inptr[col * 4 + 2];
        outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (256)] + ctab[b + (512)]) >> 16);
    }
}
