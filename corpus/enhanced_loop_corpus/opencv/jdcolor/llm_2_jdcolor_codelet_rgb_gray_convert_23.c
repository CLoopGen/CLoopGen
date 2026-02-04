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
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    JSAMPROW in0 = inptr0;
    JSAMPROW in1 = inptr1;
    JSAMPROW in2 = inptr2;
    JSAMPROW out = outptr;
    JLONG *ctab_base = ctab;
    for (col = 0; col < num_cols; col++) {
        r = *in0++;
        g = *in1++;
        b = *in2++;
        *out++ = (JSAMPLE)(((ctab_base[r] + ctab_base[g + 256] + ctab_base[b + 512]) >> 16));
    }
}
