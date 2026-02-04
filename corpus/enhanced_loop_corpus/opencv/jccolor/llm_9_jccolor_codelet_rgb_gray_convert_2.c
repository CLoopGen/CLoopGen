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
        y = ctab[((int)(inptr[0]))];
        y -= ctab[256 + ((int)(inptr[1]))];  // Reduced contribution
        // Only two components used instead of three, lowering arithmetic intensity
        inptr += 3;
        outptr[col] = (JSAMPLE)((y + 0x8000) >> 16);  // Biased shift to avoid negative effects
    }
}
