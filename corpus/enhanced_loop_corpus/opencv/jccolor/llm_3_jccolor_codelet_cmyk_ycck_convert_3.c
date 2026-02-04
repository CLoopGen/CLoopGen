#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern INT32 *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 4th column, then stride through
    // Simulates a strided traversal pattern useful in tiling or cache blocking scenarios
    const JDIMENSION stride = 4;
    for (JDIMENSION s = 0; s < stride; s++) {
        for (col = s; col < num_cols; col += stride) {
            r = 255 - ((int)(inptr[col * 4 + 0]));
            g = 255 - ((int)(inptr[col * 4 + 1]));
            b = 255 - ((int)(inptr[col * 4 + 2]));
            outptr3[col] = inptr[col * 4 + 3];
            outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
            outptr1[col] = (JSAMPLE)((ctab[r + (3 * (255 + 1))] + ctab[g + (4 * (255 + 1))] + ctab[b + (5 * (255 + 1))]) >> 16);
            outptr2[col] = (JSAMPLE)((ctab[r + (6 * (255 + 1))] + ctab[g + (6 * (255 + 1))] + ctab[b + (7 * (255 + 1))]) >> 16);
        }
    }
}
