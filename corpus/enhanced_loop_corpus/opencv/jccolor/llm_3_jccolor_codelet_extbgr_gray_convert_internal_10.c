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
    JSAMPROW r_ptr = inptr;
    JSAMPROW g_ptr = inptr + 1;
    JSAMPROW b_ptr = inptr + 2;
    for (col = 0; col < num_cols; col++) {
        r = r_ptr[0];
        g = g_ptr[0];
        b = b_ptr[0];
        r_ptr += 3;
        g_ptr += 3;
        b_ptr += 3;
        outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
    }
}
