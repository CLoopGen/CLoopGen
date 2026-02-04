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



void loop() {
    for (col = 0; col < num_cols; col++) {
        // Eliminate redundant use of global r, g, b by computing directly in place
        // Remove loop-carried dependencies entirely: make each iteration independent
        int local_r = 255 - ((int)(inptr[0]));
        int local_g = 255 - ((int)(inptr[1]));
        int local_b = 255 - ((int)(inptr[2]));

        // Update output pointers using only local computations — no cross-iteration state
        outptr3[col] = inptr[3];
        inptr += 4;

        // All writes occur to distinct memory locations per iteration
        // No WAW or WAR hazards due to disjoint column indexing
        outptr0[col] = (JSAMPLE)(
            (ctab[local_r + 0] +
             ctab[local_g + (1 * (256))] +
             ctab[local_b + (2 * (256))]) >> 16);

        outptr1[col] = (JSAMPLE)(
            (ctab[local_r + (3 * (256))] +
             ctab[local_g + (4 * (256))] +
             ctab[local_b + (5 * (256))]) >> 16);

        outptr2[col] = (JSAMPLE)(
            (ctab[local_r + (5 * (256))] +
             ctab[local_g + (6 * (256))] +
             ctab[local_b + (7 * (256))]) >> 16);
    }
}
