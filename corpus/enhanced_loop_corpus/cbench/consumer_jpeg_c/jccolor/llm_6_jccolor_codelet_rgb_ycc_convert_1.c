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
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 temp_r, temp_g, temp_b;
    for (col = 0; col < num_cols; col++) {
        temp_r = ((int)(inptr[0]));
        temp_g = ((int)(inptr[1]));
        temp_b = ((int)(inptr[2]));
        inptr += 3;

        // Introduce temporary variables to break direct WAW and WAR dependencies
        // by decoupling computation from store operations.
        INT32 val0 = (ctab[temp_r + 0] + ctab[temp_g + (1 * (255 + 1))] + ctab[temp_b + (2 * (255 + 1))]) >> 16;
        INT32 val1 = (ctab[temp_r + (3 * (255 + 1))] + ctab[temp_g + (4 * (255 + 1))] + ctab[temp_b + (5 * (255 + 1))]) >> 16;
        INT32 val2 = (ctab[temp_r + (5 * (255 + 1))] + ctab[temp_g + (6 * (255 + 1))] + ctab[temp_b + (7 * (255 + 1))]) >> 16;

        outptr0[col] = (JSAMPLE)val0;
        outptr1[col] = (JSAMPLE)val1;
        outptr2[col] = (JSAMPLE)val2;
    }
}
