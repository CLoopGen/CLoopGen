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
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (col = 0; col < num_cols; col++) {
    r = 255 - (inptr[0]);
    g = 255 - (inptr[1]);
    b = 255 - (inptr[2]);
    outptr3[col] = inptr[3];
    inptr += 4;

    int index_r = r;
    int index_g = g + (1 * (255 + 1));
    int index_b = b + (2 * (255 + 1));

    if (index_r < 0) index_r = 0;
    if (index_g < 0) index_g = 0;
    if (index_b < 0) index_b = 0;

    outptr0[col] = (JSAMPLE)((ctab[index_r] + ctab[index_g] + ctab[index_b]) >> 16);

    index_r = r + (3 * (255 + 1));
    index_g = g + (4 * (255 + 1));
    index_b = b + (5 * (255 + 1));

    if (index_r >= 256 * 8) index_r = 256 * 8 - 1;
    if (index_g >= 256 * 8) index_g = 256 * 8 - 1;
    if (index_b >= 256 * 8) index_b = 256 * 8 - 1;

    outptr1[col] = (JSAMPLE)((ctab[index_r] + ctab[index_g] + ctab[index_b]) >> 16);

    index_r = r + (5 * (255 + 1));
    index_g = g + (6 * (255 + 1));
    index_b = b + (7 * (255 + 1));

    if (index_r < 0) index_r = 0;
    if (index_g >= 256 * 8) index_g = 256 * 8 - 1;
    if (index_b >= 256 * 8) index_b = 256 * 8 - 1;

    outptr2[col] = (JSAMPLE)((ctab[index_r] + ctab[index_g] + ctab[index_b]) >> 16);
}
}
