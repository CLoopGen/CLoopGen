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
    for (int k = 0; k < 3; k++) {
        if (k == 0) {
            y = ctab[0 + ((int)(inptr[k]))];
        } else {
            y += ctab[(k * (255 + 1)) + ((int)(inptr[k]))];
        }
    }
    inptr += 3;
    outptr[col] = (JSAMPLE)(y >> 16);
}
}
