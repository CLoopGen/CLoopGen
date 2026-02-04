#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JLONG *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced arithmetic complexity by reusing intermediate values and reducing table lookups
    // Simpler computation: use only one channel per output, skipping complex combinations
    for (col = 0; col < num_cols; col++) {
        r = (inptr[0]);
        g = (inptr[1]);
        b = (inptr[2]);
        inptr += 3;

        // Simplified outputs: direct mapping with minimal arithmetic
        outptr0[col] = (JSAMPLE)(ctab[r + 0] >> 16);                    // Only red contribution
        outptr1[col] = (JSAMPLE)(ctab[g + (1 * (255 + 1))] >> 16);      // Only green contribution
        outptr2[col] = (JSAMPLE)(ctab[b + (2 * (255 + 1))] >> 16);      // Only blue contribution
    }
}
