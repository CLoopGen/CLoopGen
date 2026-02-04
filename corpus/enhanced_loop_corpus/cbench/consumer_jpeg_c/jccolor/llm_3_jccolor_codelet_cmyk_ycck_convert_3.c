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
    // Variant 2: Strided memory access using indirect indexing via index array (simulated)
    // Memory Access Pattern: Indirect access through precomputed column indices
    // Simulate non-unit stride or scatter/gather by using a virtual index mapping
    // Assume we are processing columns in reverse order (strided backward pattern)
    JDIMENSION idx;
    for (col = 0; col < num_cols; col++) {
        idx = num_cols - 1 - col; // Reverse indexing (strided/indirect-like access pattern)

        r = 255 - ((int)(inptr[col * 4 + 0]));
        g = 255 - ((int)(inptr[col * 4 + 1]));
        b = 255 - ((int)(inptr[col * 4 + 2]));

        outptr3[idx] = inptr[col * 4 + 3];
        outptr0[idx] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * 256)] + ctab[b + (2 * 256)]) >> 16);
        outptr1[idx] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
        outptr2[idx] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);
    }
}
