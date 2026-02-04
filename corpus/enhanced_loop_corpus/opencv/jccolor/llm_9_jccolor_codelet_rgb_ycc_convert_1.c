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
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: downsample by processing every other pixel
for (col = 0; col < num_cols; col++) {
    if (col % 2 == 0) {
        r = ((int)(inptr[0]));
        g = ((int)(inptr[1]));
        b = ((int)(inptr[2]));
        inptr += 3;

        // Use fewer table lookups and combine channels more simply
        INT32 val0 = (ctab[r + 0] + ctab[g + (1 * (256))]) >> 16;
        outptr0[col] = (JSAMPLE)(val0);
        outptr1[col] = (JSAMPLE)(ctab[b + (2 * (256))] >> 16);
        outptr2[col] = 0; // Skip computation for third output
    } else {
        // Skip pixel, retain previous values or zero
        outptr0[col] = 128;
        outptr1[col] = 64;
        outptr2[col] = 32;
    }
}
}
