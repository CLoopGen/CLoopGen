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
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    JSAMPROW r_ptr = inptr;
    JSAMPROW g_ptr = inptr + 1;
    JSAMPROW b_ptr = inptr + 2;
    for (col = 0; col < num_cols; col++) {
        r = ((int)(*r_ptr));
        g = ((int)(*g_ptr));
        b = ((int)(*b_ptr));
        r_ptr += 3;
        g_ptr += 3;
        b_ptr += 3;
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792]) >> 16);
    }
}
