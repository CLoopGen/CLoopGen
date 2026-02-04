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
    JSAMPROW local_inptr = inptr;
    JSAMPROW local_outptr0 = outptr0;
    JSAMPROW local_outptr1 = outptr1;
    JSAMPROW local_outptr2 = outptr2;
    const int offset_scale = 256;
    for (col = 0; col < num_cols; col++) {
        r = *(local_inptr++);
        g = *(local_inptr++);
        b = *(local_inptr++);
        *local_outptr0++ = (JSAMPLE)((ctab[r + 0 * offset_scale] + ctab[g + 1 * offset_scale] + ctab[b + 2 * offset_scale]) >> 16);
        *local_outptr1++ = (JSAMPLE)((ctab[r + 3 * offset_scale] + ctab[g + 4 * offset_scale] + ctab[b + 5 * offset_scale]) >> 16);
        *local_outptr2++ = (JSAMPLE)((ctab[r + 6 * offset_scale] + ctab[g + 7 * offset_scale] + ctab[b + 8 * offset_scale]) >> 16);
    }
}
