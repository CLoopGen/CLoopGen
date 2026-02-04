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
    for (col = 0; col < num_cols; col++) {
        r = ((int)(inptr[0]));
        g = ((int)(inptr[1]));
        b = ((int)(inptr[2]));
        inptr += 3;
        INT32 val_r = ctab[r];
        INT32 val_g = ctab[g + 256];
        INT32 val_b = ctab[b + 512];
        INT32 sum = val_r + val_g + val_b;
        INT32 shifted = sum >> 16;
        outptr[col] = (JSAMPLE)shifted;
    }
}
