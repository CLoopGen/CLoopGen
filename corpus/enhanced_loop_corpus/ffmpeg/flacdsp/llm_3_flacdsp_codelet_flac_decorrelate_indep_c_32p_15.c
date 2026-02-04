#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int32_t **samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Pointer Arithmetic
    // Use pointer arithmetic to access array elements indirectly.
    // We precompute base pointers for each row and step through them using pointer increments.
    // This avoids repeated index calculations and simulates indirect access patterns.

    int32_t **in_ptr = in;
    int32_t **samples_ptr = samples;

    for (j = 0; j < len; j++) {
        for (i = 0; i < channels; i++) {
            int32_t *in_row = in_ptr[i];
            int32_t *samples_row = samples_ptr[i];
            samples_row[j] = (int)((unsigned int)in_row[j] << shift);
        }
    }
}
