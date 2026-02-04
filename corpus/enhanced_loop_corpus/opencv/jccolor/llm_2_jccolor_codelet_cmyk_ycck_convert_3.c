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
    // Variant 1: Consecutive memory access with local array indexing and unrolling by 2
    INT32 *ctab_base_r = ctab;
    INT32 *ctab_base_g = ctab + (255 + 1);
    INT32 *ctab_base_b = ctab + (2 * (255 + 1));
    for (col = 0; col + 1 < num_cols; col += 2) {
        // First pixel
        r = 255 - ((int)(inptr[0]));
        g = 255 - ((int)(inptr[1]));
        b = 255 - ((int)(inptr[2]));
        outptr3[col] = inptr[3];
        outptr0[col] = (JSAMPLE)((ctab_base_r[r] + ctab_base_g[g] + ctab_base_b[b]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * (255 + 1))] + ctab[g + (4 * (255 + 1))] + ctab[b + (5 * (255 + 1))]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (6 * (255 + 1))] + ctab[g + (6 * (255 + 1))] + ctab[b + (7 * (255 + 1))]) >> 16);

        // Second pixel
        r = 255 - ((int)(inptr[4]));
        g = 255 - ((int)(inptr[5]));
        b = 255 - ((int)(inptr[6]));
        outptr3[col + 1] = inptr[7];
        outptr0[col + 1] = (JSAMPLE)((ctab_base_r[r] + ctab_base_g[g] + ctab_base_b[b]) >> 16);
        outptr1[col + 1] = (JSAMPLE)((ctab[r + (3 * (255 + 1))] + ctab[g + (4 * (255 + 1))] + ctab[b + (5 * (255 + 1))]) >> 16);
        outptr2[col + 1] = (JSAMPLE)((ctab[r + (6 * (255 + 1))] + ctab[g + (6 * (255 + 1))] + ctab[b + (7 * (255 + 1))]) >> 16);

        inptr += 8;
    }
    // Handle remaining pixel if num_cols is odd
    if (col < num_cols) {
        r = 255 - ((int)(inptr[0]));
        g = 255 - ((int)(inptr[1]));
        b = 255 - ((int)(inptr[2]));
        outptr3[col] = inptr[3];
        inptr += 4;
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * (255 + 1))] + ctab[g + (4 * (255 + 1))] + ctab[b + (5 * (255 + 1))]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (6 * (255 + 1))] + ctab[g + (6 * (255 + 1))] + ctab[b + (7 * (255 + 1))]) >> 16);
    }
}
