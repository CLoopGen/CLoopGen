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
    for (col = 0; col < num_cols; col++) {
        int r_next = 255 - ((int)(inptr[0]));
        int g_next = 255 - ((int)(inptr[1]));
        int b_next = 255 - ((int)(inptr[2]));
        outptr3[col] = inptr[3];
        inptr += 4;
        // Eliminated loop-carried dependency on r, g, b by using local temporaries and reordering computation
        // Introduces parallelism: all three output pointers can be computed independently
        outptr0[col] = (JSAMPLE)((ctab[r_next + 0] + ctab[g_next + (1 * (255 + 1))] + ctab[b_next + (2 * (255 + 1))]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r_next + (3 * (255 + 1))] + ctab[g_next + (4 * (255 + 1))] + ctab[b_next + (5 * (255 + 1))]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r_next + (5 * (255 + 1))] + ctab[g_next + (6 * (255 + 1))] + ctab[b_next + (7 * (255 + 1))]) >> 16);
        // WAW dependencies removed by eliminating reuse of r/g/b across iterations
    }
}
