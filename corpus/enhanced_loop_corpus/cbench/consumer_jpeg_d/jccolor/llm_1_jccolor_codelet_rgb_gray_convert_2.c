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
    JDIMENSION temp_col = 0;
    for (col = 0; col < num_cols; col++) {
        for (temp_col = col; temp_col <= col; temp_col++) {  // Degenerate inner loop, depth increased but logically equivalent
            r = ((int)(inptr[0]));
            g = ((int)(inptr[1]));
            b = ((int)(inptr[2]));
            inptr += 3;
            outptr[temp_col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
        }
    }
}
