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
    INT32 temp_sum = 0;
    for (col = 0; col < num_cols; col++) {
        temp_sum = ctab[0 + ((int)(inptr[0]))];
        temp_sum += ctab[(1 * (256)) + ((int)(inptr[1]))];
        temp_sum += ctab[(2 * (256)) + ((int)(inptr[2]))];
        inptr += 3;
        outptr[col] = (JSAMPLE)((temp_sum + y) >> 16);
    }
}
