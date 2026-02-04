#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col += 2) {
        // Process two pixels per iteration to increase computational intensity
        if (col + 1 < num_cols) {
            // First pixel
            outptr[2] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[0] = inptr2[col];
            outptr[3] = 255;
            // Second pixel
            outptr[6] = inptr0[col + 1];
            outptr[5] = inptr1[col + 1];
            outptr[4] = inptr2[col + 1];
            outptr[7] = 255;
            outptr += 8;
        } else {
            // Handle odd-sized row
            outptr[2] = inptr0[col];
            outptr[1] = inptr1[col];
            outptr[0] = inptr2[col];
            outptr[3] = 255;
            outptr += 4;
        }
    }
}
