#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef JSAMPARRAY *JSAMPIMAGE;

typedef unsigned int JDIMENSION;

extern JSAMPIMAGE input_buf;
extern JDIMENSION input_row;
extern JSAMPARRAY output_buf;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern int num_components;
extern JDIMENSION num_cols;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Read with Fixed Base and Indirect Component Access
    // We change the access pattern to use a fixed base pointer for each component
    // and stride through the input arrays with direct indexing, while maintaining
    // the original strided write pattern in output.

    JSAMPROW bases[3];  // Assume max practical components (e.g., RGB), can be adjusted
    int n = num_components;

    // Precompute base pointers for each component
    for (ci = 0; ci < n; ci++) {
        bases[ci] = input_buf[ci][input_row];
    }

    outptr = *output_buf;
    for (col = 0; col < num_cols; col++) {
        for (ci = 0; ci < n; ci++) {
            outptr[ci] = bases[ci][col];
        }
        outptr += num_components;
    }
}
