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
    // Variant 2: Strided input access with direct index arithmetic (interleaved RGB treated as stride-3)
    for (col = 0; col < num_cols; col++) {
        JDIMENSION idx = col * 3;
        r = ((int)(inptr[idx + 0]));
        g = ((int)(inptr[idx + 1]));
        b = ((int)(inptr[idx + 2]));
        outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
    }
}
