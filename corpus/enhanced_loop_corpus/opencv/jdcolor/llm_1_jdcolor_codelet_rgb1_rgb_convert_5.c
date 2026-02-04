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
    JDIMENSION block_size = 4;
    JDIMENSION remainder = num_cols % block_size;
    JDIMENSION i, j;

    for (i = 0; i <= num_cols - block_size; i += block_size) {
        for (j = 0; j < block_size; j++) {
            col = i + j;
            r = ((int)(inptr0[col]));
            g = ((int)(inptr1[col]));
            b = ((int)(inptr2[col]));
            outptr[0] = (JSAMPLE)((r + g - 128) & 255);
            outptr[1] = (JSAMPLE)g;
            outptr[2] = (JSAMPLE)((b + g - 128) & 255);
            outptr += 3;
        }
    }

    for (col = num_cols - remainder; col < num_cols; col++) {
        r = ((int)(inptr0[col]));
        g = ((int)(inptr1[col]));
        b = ((int)(inptr2[col]));
        outptr[0] = (JSAMPLE)((r + g - 128) & 255);
        outptr[1] = (JSAMPLE)g;
        outptr[2] = (JSAMPLE)((b + g - 128) & 255);
        outptr += 3;
    }
}
