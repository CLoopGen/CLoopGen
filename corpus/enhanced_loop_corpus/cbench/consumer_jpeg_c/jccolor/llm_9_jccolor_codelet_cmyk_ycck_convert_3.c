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
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced arithmetic operations by precomputing constant offsets and simplifying expressions
const INT32 offset_g1 = (1 * 256);
const INT32 offset_b2 = (2 * 256);
const INT32 offset_r3 = (3 * 256);
const INT32 offset_g4 = (4 * 256);
const INT32 offset_b5 = (5 * 256);
const INT32 offset_r5 = (5 * 256);  // reused for third output
const INT32 offset_g6 = (6 * 256);
const INT32 offset_b7 = (7 * 256);

for (col = 0; col < num_cols; col++) {
    r = 255 - inptr[0];
    g = 255 - inptr[1];
    b = 255 - inptr[2];
    outptr3[col] = inptr[3];
    inptr += 4;

    // Combine lookups with precomputed offsets to reduce arithmetic during indexing
    outptr0[col] = (JSAMPLE)((ctab[r] + ctab[g + offset_g1] + ctab[b + offset_b2]) >> 16);
    outptr1[col] = (JSAMPLE)((ctab[r + offset_r3] + ctab[g + offset_g4] + ctab[b + offset_b5]) >> 16);
    outptr2[col] = (JSAMPLE)((ctab[r + offset_r5] + ctab[g + offset_g6] + ctab[b + offset_b7]) >> 16);
}
}
