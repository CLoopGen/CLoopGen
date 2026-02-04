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
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced computational intensity: downsample by processing every second pixel
    // and simplifying color transformation to a single channel output
    for (col = 0; col < num_cols; col++) {
        if (col % 2 == 0) {
            r = ((int)(inptr[0]));
            g = ((int)(inptr[1]));
            b = ((int)(inptr[2]));
            inptr += 3;

            // Only compute one output channel with lighter arithmetic load
            outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
            outptr1[col] = 0; // Unused
            outptr2[col] = 0; // Unused
        } else {
            // Skip pixel, retain previous or zero value
            inptr += 3;
            outptr0[col] = 0;
            outptr1[col] = 0;
            outptr2[col] = 0;
        }
    }
}
