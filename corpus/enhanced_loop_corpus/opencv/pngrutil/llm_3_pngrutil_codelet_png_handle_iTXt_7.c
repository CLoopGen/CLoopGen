#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 length;
extern png_bytep buffer;
extern png_uint_32 prefix_length;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    png_uint_32 i;
    png_uint_32 *indices = (png_uint_32*)malloc(sizeof(png_uint_32) * length);
    if (!indices) return; // Handle allocation failure

    // Precompute indirect indices (simple identity mapping for realism, could be shuffled)
    for (i = 0; i < length; ++i) {
        indices[i] = i;
    }

    prefix_length = 0;
    for (i = 0; i < length; ++i) {
        png_uint_32 idx = indices[i]; // Use indirect index
        if (buffer[idx] == 0) {
            break;
        }
        prefix_length = i + 1;
    }

    free(indices);
}
