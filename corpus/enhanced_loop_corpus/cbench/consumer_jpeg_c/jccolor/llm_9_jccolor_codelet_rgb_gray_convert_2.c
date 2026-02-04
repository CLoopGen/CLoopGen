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
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION step = 1;
    for (col = 0; col < num_cols; col += step) {
        r = ((int)(inptr[0])) << 1;
        g = ((int)(inptr[1])) << 1;
        b = ((int)(inptr[2])) << 1;
        inptr += 3;
        INT32 val_r = ctab[(r >> 1) + 0];
        INT32 val_g = ctab[(g >> 1) + 256];
        INT32 val_b = ctab[(b >> 1) + 512];
        INT32 sum = (val_r + val_g + val_b) >> 16;
        sum = (sum < 0) ? 0 : ((sum > 255) ? 255 : sum);
        outptr[col] = (JSAMPLE)sum;
    }
}
