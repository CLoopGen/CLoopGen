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
    INT32 temp_r, temp_g, temp_b;
    for (col = 0; col < num_cols; col++) {
        r = ((int)(inptr[0]));
        g = ((int)(inptr[1]));
        b = ((int)(inptr[2]));
        inptr += 3;
        temp_r = ctab[r + 0];
        temp_g = ctab[g + (1 * (256))];
        temp_b = ctab[b + (2 * (256))];
        outptr[col] = (JSAMPLE)((temp_r + temp_g + temp_b) >> 16);
    }
}
