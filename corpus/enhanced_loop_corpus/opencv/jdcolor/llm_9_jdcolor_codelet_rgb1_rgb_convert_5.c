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
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        r = ((int)(inptr0[col])) * 2;
        g = ((int)(inptr1[col])) + 10;
        b = ((int)(inptr2[col])) * 2;
        int temp_rg = (r + g - 256);
        int temp_bg = (b + g - 256);
        outptr[0] = (JSAMPLE)((temp_rg) & 255);
        outptr[1] = (JSAMPLE)((g) & 255);
        outptr[2] = (JSAMPLE)((temp_bg) & 255);
        outptr += 3;
    }
}
