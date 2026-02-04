#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JLONG rgb;
extern unsigned int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION double_col;
    for (double_col = 0; double_col < (num_cols >> 1); double_col += 2) {
        // First iteration unrolled
        g = *inptr++;
        rgb = ((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3));
        g = *inptr++;
        rgb = ((((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3)) << 16) | rgb);
        ((*(int *)(outptr)) = rgb);
        outptr += 4;

        // Second iteration unrolled (if within bounds)
        if (double_col + 1 < (num_cols >> 1)) {
            g = *inptr++;
            rgb = ((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3));
            g = *inptr++;
            rgb = ((((((g) << 8) & 63488) | (((g) << 3) & 2016) | ((g) >> 3)) << 16) | rgb);
            ((*(int *)(outptr)) = rgb);
            outptr += 4;
        }
    }
}
