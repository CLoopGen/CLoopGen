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
    int temp_r, temp_g, temp_b;
    for (col = 0; col < num_cols; col++) {
        temp_r = ((int)(inptr0[col]));
        temp_g = ((int)(inptr1[col]));
        temp_b = ((int)(inptr2[col]));
        r = temp_r;
        g = temp_g;
        b = temp_b;
        outptr[0] = (JSAMPLE)((r + g - 128) & 255);
        outptr[1] = (JSAMPLE)g;
        outptr[2] = (JSAMPLE)((b + g - 128) & 255);
        outptr += 3;
    }
}
