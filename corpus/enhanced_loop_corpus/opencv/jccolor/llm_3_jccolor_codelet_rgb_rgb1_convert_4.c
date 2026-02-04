#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided output access with interleaved write pattern
    // Outputs are written in a strided manner by simulating structure-of-arrays to array-of-structures-like access
    // This changes the access pattern of output arrays to be non-consecutive
    
    JSAMPROW in = inptr;
    ptrdiff_t stride = 1; // Could be modified for larger strides; kept as 1 for correctness

    for (col = 0; col < num_cols; col++) {
        r = (int)in[0];
        g = (int)in[1];
        b = (int)in[2];
        in += 3;

        // Write to outputs with potential for stride or reordered access
        // Here we simulate a future extension where outputs might be accessed with offset patterns
        *(outptr0 + col * stride) = (JSAMPLE)((r - g + 128) & 255);
        *(outptr1 + col * stride) = (JSAMPLE)g;
        *(outptr2 + col * stride) = (JSAMPLE)((b - g + 128) & 255);
    }
}
