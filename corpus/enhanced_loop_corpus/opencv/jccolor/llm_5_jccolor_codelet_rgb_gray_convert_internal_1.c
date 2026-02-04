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
    for (col = 0; col < num_cols; col++) {
        r = (inptr[0]);
        g = (inptr[1]);
        b = (inptr[2]);
        inptr += 3;

        JLONG r_val = ctab[r + 0];
        JLONG g_val = ctab[g + (1 * (256))];
        JLONG b_val = ctab[b + (2 * (256))];

        JLONG sum = r_val + g_val + b_val;

        if (sum > (1 << 16)) {
            outptr[col] = (JSAMPLE)(sum >> 16);
        } else {
            outptr[col] = 128;
        }
    }
}
