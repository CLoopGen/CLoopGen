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
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            y = ctab[0 + ((int)(inptr[0]))];
            y += ctab[(1 * (256)) + ((int)(inptr[1]))];
            y += ctab[(2 * (256)) + ((int)(inptr[2]))];
            outptr[col] = (JSAMPLE)(y >> 16);
            
            y = ctab[0 + ((int)(inptr[3]))];
            y += ctab[(1 * (256)) + ((int)(inptr[4]))];
            y += ctab[(2 * (256)) + ((int)(inptr[5]))];
            outptr[col + 1] = (JSAMPLE)(y >> 16);
            
            inptr += 6;
        } else {
            y = ctab[0 + ((int)(inptr[0]))];
            y += ctab[(1 * (256)) + ((int)(inptr[1]))];
            y += ctab[(2 * (256)) + ((int)(inptr[2]))];
            outptr[col] = (JSAMPLE)(y >> 16);
            inptr += 3;
        }
    }
}
