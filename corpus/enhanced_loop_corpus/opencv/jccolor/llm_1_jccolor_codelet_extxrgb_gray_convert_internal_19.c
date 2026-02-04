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
    JDIMENSION col;
    if (num_cols > 0) {
        for (col = 0; col < num_cols; col += 2) {
            // First element
            r = (inptr[1]);
            g = (inptr[2]);
            b = (inptr[3]);
            inptr += 4;
            outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);

            // Second element (if within bounds)
            if (col + 1 < num_cols) {
                r = (inptr[1]);
                g = (inptr[2]);
                b = (inptr[3]);
                inptr += 4;
                outptr[col + 1] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
            }
        }
    }
}
