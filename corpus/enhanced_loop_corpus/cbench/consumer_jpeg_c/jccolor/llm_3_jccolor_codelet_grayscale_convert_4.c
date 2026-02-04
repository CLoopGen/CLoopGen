#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern int instride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided input access with reversed output order (indirect-like pattern via index mapping)
    JDIMENSION col;
    for (col = 0; col < num_cols; col++) {
        JDIMENSION rev_index = num_cols - 1 - col;  // Reverse output index
        outptr[rev_index] = inptr[col * instride];
    }
}
