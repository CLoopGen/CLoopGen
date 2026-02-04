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
    // Variant 1: Consecutive memory access with loop unrolling (factor of 2)
    // Memory Access Pattern: Sequential and coalesced writes, input read stride remains 4
    // Unroll the loop by 2 to increase data locality and reduce loop overhead
    col = 0;
    INT32 limit = num_cols - 1;
    for (; col < limit; col += 2) {
        // First iteration
        r = 255 - ((int)(inptr[0]));
        g = 255 - ((int)(inptr[1]));
        b = 255 - ((int)(inptr[2]));
        outptr3[col] = inptr[3];
        inptr += 4;
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * 256)] + ctab[b + (2 * 256)]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);

        // Second iteration
        r = 255 - ((int)(inptr[0]));
        g = 255 - ((int)(inptr[1]));
        b = 255 - ((int)(inptr[2]));
        outptr3[col+1] = inptr[3];
        inptr += 4;
        outptr0[col+1] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * 256)] + ctab[b + (2 * 256)]) >> 16);
        outptr1[col+1] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
        outptr2[col+1] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);
    }
    // Handle remaining element if num_cols is odd
    if (col < num_cols) {
        r = 255 - ((int)(inptr[0]));
        g = 255 - ((int)(inptr[1]));
        b = 255 - ((int)(inptr[2]));
        outptr3[col] = inptr[3];
        inptr += 4;
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * 256)] + ctab[b + (2 * 256)]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);
    }
}
