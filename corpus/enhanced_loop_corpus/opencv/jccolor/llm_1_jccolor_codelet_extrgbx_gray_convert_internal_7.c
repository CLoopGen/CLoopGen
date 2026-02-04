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
    JDIMENSION block_size = 4;
    JDIMENSION i, j;
    for (i = 0; i < num_cols; i += block_size) {
        for (j = i; j < i + block_size && j < num_cols; j++) {
            col = j;
            r = (inptr[0]);
            g = (inptr[1]);
            b = (inptr[2]);
            inptr += 4;
            outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
        }
    }
}
