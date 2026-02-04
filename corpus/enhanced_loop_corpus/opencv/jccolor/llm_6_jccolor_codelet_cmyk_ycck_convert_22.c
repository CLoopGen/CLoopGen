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
    JLONG temp_r, temp_g, temp_b;
    for (col = 0; col < num_cols; col++) {
        r = 255 - (inptr[0]);
        g = 255 - (inptr[1]);
        b = 255 - (inptr[2]);
        temp_r = r;
        temp_g = g;
        temp_b = b;
        inptr += 4;
        outptr3[col] = inptr[-1];
        outptr0[col] = (JSAMPLE)((ctab[temp_r + 0] + ctab[temp_g + (1 * (255 + 1))] + ctab[temp_b + (2 * (255 + 1))]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[temp_r + (3 * (255 + 1))] + ctab[temp_g + (4 * (255 + 1))] + ctab[temp_b + (5 * (255 + 1))]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[temp_r + (5 * (255 + 1))] + ctab[temp_g + (6 * (255 + 1))] + ctab[temp_b + (7 * (255 + 1))]) >> 16);
    }
}
