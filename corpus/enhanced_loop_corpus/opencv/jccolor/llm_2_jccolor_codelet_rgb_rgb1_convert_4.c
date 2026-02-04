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
    // Variant 1: Consecutive memory access with local array for output buffering
    // Instead of writing directly to outptr0, outptr1, outptr2 with strided input,
    // we process multiple elements at once and maintain spatial locality.
    
    JSAMPROW in = inptr;
    JSAMPROW out0 = outptr0;
    JSAMPROW out1 = outptr1;
    JSAMPROW out2 = outptr2;

    for (col = 0; col < num_cols; col++) {
        r = (int)in[0];
        g = (int)in[1];
        b = (int)in[2];
        
        // Process and store using direct indexing on outputs
        out0[col] = (JSAMPLE)((r - g + 128) & 255);
        out1[col] = (JSAMPLE)g;
        out2[col] = (JSAMPLE)((b - g + 128) & 255);

        in += 3; // Strided input read (original pattern preserved for input)
    }
}
