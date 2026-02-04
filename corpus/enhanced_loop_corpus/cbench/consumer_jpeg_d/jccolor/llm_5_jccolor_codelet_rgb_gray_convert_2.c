#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern INT32 *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (col = 0; col < num_cols; col++) {
    r = ((int)(inptr[0]));
    g = ((int)(inptr[1]));
    b = ((int)(inptr[2]));
    inptr += 3;

    if (r < 0 || r > 255) continue;
    if (g < 0 || g > 255) continue;
    if (b < 0 || b > 255) continue;

    outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
}
}
