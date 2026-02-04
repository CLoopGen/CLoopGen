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
    // Variant 2: Strided memory access with reversed input traversal (simulating different stride pattern)
    JDIMENSION idx;
    JSAMPROW rev_inptr = inptr + (num_cols - 1) * 3; // Point to last RGB triplet

    for (col = 0; col < num_cols; col++) {
        idx = num_cols - 1 - col; // Reverse index
        r = rev_inptr[0];
        g = rev_inptr[1];
        b = rev_inptr[2];
        rev_inptr -= 3;

        outptr0[idx] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
        outptr1[idx] = (JSAMPLE)((ctab[r + (3 * (255 + 1))] + ctab[g + (4 * (255 + 1))] + ctab[b + (5 * (255 + 1))]) >> 16);
        outptr2[idx] = (JSAMPLE)((ctab[r + (5 * (255 + 1))] + ctab[g + (6 * (255 + 1))] + ctab[b + (7 * (255 + 1))]) >> 16);
    }
}
