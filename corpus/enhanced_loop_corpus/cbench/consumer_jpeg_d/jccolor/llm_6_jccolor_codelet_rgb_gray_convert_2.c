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
    int temp_r, temp_g, temp_b;
    for (col = 0; col < num_cols; col++) {
        temp_r = ((int)(inptr[0]));
        temp_g = ((int)(inptr[1]));
        temp_b = ((int)(inptr[2]));
        inptr += 3;
        r = temp_r;
        g = temp_g;
        b = temp_b;
        outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
    }
}
