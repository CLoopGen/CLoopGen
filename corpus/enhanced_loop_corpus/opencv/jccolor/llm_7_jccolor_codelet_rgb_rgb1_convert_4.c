#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_g = 0;
for (col = 0; col < num_cols; col++) {
    r = ((int)(inptr[0]));
    g = ((int)(inptr[1]));
    b = ((int)(inptr[2]));
    inptr += 3;
    int adjusted_r = (r - prev_g + 128) & 255;
    int adjusted_b = (b - prev_g + 128) & 255;
    outptr0[col] = (JSAMPLE)adjusted_r;
    outptr1[col] = (JSAMPLE)g;
    outptr2[col] = (JSAMPLE)adjusted_b;
    prev_g = g;
}
}
