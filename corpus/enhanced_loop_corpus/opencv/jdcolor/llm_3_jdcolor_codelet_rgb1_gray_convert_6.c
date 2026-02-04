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
extern INT32 y;
extern INT32 *Rytab;
extern INT32 *Gytab;
extern INT32 *Bytab;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2 (process every second element)
    JDIMENSION step = 2;
    JDIMENSION end_col = (num_cols & ~1); // Make sure it's even to avoid overflow
    for (col = 0; col < end_col; col += step) {
        r = ((int)(inptr0[col]));
        g = ((int)(inptr1[col]));
        b = ((int)(inptr2[col]));
        y = Rytab[(r + g - 128) & 255];
        y += Gytab[g];
        y += Bytab[(b + g - 128) & 255];
        outptr[col] = (JSAMPLE)(y >> 16);

        // Handle next element in stride (col+1) if within bounds
        JDIMENSION next_col = col + 1;
        if (next_col < num_cols) {
            r = ((int)(inptr0[next_col]));
            g = ((int)(inptr1[next_col]));
            b = ((int)(inptr2[next_col]));
            y = Rytab[(r + g - 128) & 255];
            y += Gytab[g];
            y += Bytab[(b + g - 128) & 255];
            outptr[next_col] = (JSAMPLE)(y >> 16);
        }
    }
    // Handle any remaining odd-sized tail
    if (col < num_cols) {
        r = ((int)(inptr0[col]));
        g = ((int)(inptr1[col]));
        b = ((int)(inptr2[col]));
        y = Rytab[(r + g - 128) & 255];
        y += Gytab[g];
        y += Bytab[(b + g - 128) & 255];
        outptr[col] = (JSAMPLE)(y >> 16);
    }
}
