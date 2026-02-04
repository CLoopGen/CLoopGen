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
    INT32 local_y;
    for (col = 0; col < num_cols; col++) {
        local_y = ctab[0 + ((int)(inptr[0]))];
        local_y += ctab[(1 * (255 + 1)) + ((int)(inptr[1]))];
        inptr += 2;
        local_y += ctab[(2 * (255 + 1)) + ((int)(inptr[0]))];
        inptr += 1;
        outptr[col] = (JSAMPLE)(local_y >> 16);
        y = local_y; // WAW dependency: write-after-write on 'y' removed loop-carried dependency
    }
}
