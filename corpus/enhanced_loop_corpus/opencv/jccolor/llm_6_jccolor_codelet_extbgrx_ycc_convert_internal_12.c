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
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (col = 0; col < num_cols; col++) {
    r = (inptr[2]);
    g = (inptr[1]);
    b = (inptr[0]);
    inptr += 4;
    JLONG temp_r = ctab[r + 0];
    JLONG temp_g = ctab[g + (1 * (255 + 1))];
    JLONG temp_b = ctab[b + (2 * (255 + 1))];
    outptr0[col] = (JSAMPLE)((temp_r + temp_g + temp_b) >> 16);
    temp_r = ctab[r + (3 * (255 + 1))];
    temp_g = ctab[g + (4 * (255 + 1))];
    temp_b = ctab[b + (5 * (255 + 1))];
    outptr1[col] = (JSAMPLE)((temp_r + temp_g + temp_b) >> 16);
    temp_r = ctab[r + (5 * (255 + 1))];
    temp_g = ctab[g + (6 * (255 + 1))];
    temp_b = ctab[b + (7 * (255 + 1))];
    outptr2[col] = (JSAMPLE)((temp_r + temp_g + temp_b) >> 16);
}
}
