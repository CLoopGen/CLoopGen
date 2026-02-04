#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce arithmetic operations by precomputing offsets and simplifying expressions
const INT32 offset1 = 1 * 256;
const INT32 offset2 = 2 * 256;
const INT32 offset3 = 3 * 256;
const INT32 offset4 = 4 * 256;
const INT32 offset5 = 5 * 256;
const INT32 offset6 = 6 * 256;
const INT32 offset7 = 7 * 256;

for (col = 0; col < num_cols; col++) {
    r = 255 - inptr[0];
    g = 255 - inptr[1];
    b = 255 - inptr[2];
    outptr3[col] = inptr[3];
    inptr += 4;

    // Combine lookups with precomputed constant offsets to reduce expression complexity
    outptr0[col] = (JSAMPLE)((ctab[r] + ctab[g + offset1] + ctab[b + offset2]) >> 16);
    outptr1[col] = (JSAMPLE)((ctab[r + offset3] + ctab[g + offset4] + ctab[b + offset5]) >> 16);
    outptr2[col] = (JSAMPLE)((ctab[r + offset5] + ctab[g + offset6] + ctab[b + offset7]) >> 16);
}
}
