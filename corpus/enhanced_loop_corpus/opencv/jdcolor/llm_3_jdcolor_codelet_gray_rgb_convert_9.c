#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Instead of writing three consecutive output values per input, we now write with a fixed stride
    // to simulate scattering data across a wider output region (e.g., simulating planar or interleaved format).
    JDIMENSION col;
    const ptrdiff_t stride = 16; // Assume output buffer is organized with larger stride
    JSAMPROW base_out = outptr;

    for (col = 0; col < num_cols; col++) {
        // Write to strided locations instead of consecutive
        base_out[0 * stride] = inptr[col];
        base_out[1 * stride] = inptr[col];
        base_out[2 * stride] = inptr[col];
        base_out += 3; // Move to next group of strided positions (base pointer walk)
    }
    outptr = base_out; // Maintain consistency with original side effect
}
