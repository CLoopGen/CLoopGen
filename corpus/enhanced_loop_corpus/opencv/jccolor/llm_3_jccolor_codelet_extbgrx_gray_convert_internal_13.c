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
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW local_inptr = inptr;
    JSAMPROW local_outptr = outptr;
    JLONG *local_ctab = ctab;
    for (col = 0; col < num_cols; col++) {
        r = local_inptr[2];
        g = local_inptr[1];
        b = local_inptr[0];
        local_inptr += 4;
        size_t idx_r = r;
        size_t idx_g = g + (1 * (256));
        size_t idx_b = b + (2 * (256));
        local_outptr[col] = (JSAMPLE)((local_ctab[idx_r] + local_ctab[idx_g] + local_ctab[idx_b]) >> 16);
    }
}
