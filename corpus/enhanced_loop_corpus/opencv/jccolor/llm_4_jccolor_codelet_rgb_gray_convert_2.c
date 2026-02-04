#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern INT32 y;
extern INT32 *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        if (col % 2 == 0) {
            y = ctab[0 + ((int)(inptr[0]))];
            y += ctab[(1 * (256)) + ((int)(inptr[1]))];
            y += ctab[(2 * (256)) + ((int)(inptr[2]))];
            inptr += 3;
        } else {
            y = ctab[(0 * 256) + ((int)(inptr[0]))] +
                ctab[(1 * 256) + ((int)(inptr[1]))] +
                ctab[(2 * 256) + ((int)(inptr[2]))];
            inptr += 3;
        }
        outptr[col] = (JSAMPLE)(y >> 16);
    }
}
