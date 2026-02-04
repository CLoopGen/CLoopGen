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
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const JDIMENSION stride = 256;
    JSAMPROW r_ptr = inptr;
    JSAMPROW g_ptr = inptr + 1;
    JSAMPROW b_ptr = inptr + 2;
    for (col = 0; col < num_cols; col++) {
        r = ((int)(r_ptr[col * 3]));
        g = ((int)(g_ptr[col * 3]));
        b = ((int)(b_ptr[col * 3]));
        outptr0[col] = (JSAMPLE)((ctab[r + 0 * stride] + ctab[g + 1 * stride] + ctab[b + 2 * stride]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + 3 * stride] + ctab[g + 4 * stride] + ctab[b + 5 * stride]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + 6 * stride] + ctab[g + 7 * stride] + ctab[b + 8 * stride]) >> 16);
    }
}
