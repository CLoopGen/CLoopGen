#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *data;
extern double *w_data;
extern int i;
extern int n2;
extern double w;
extern double c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access
    // Introduce strided access pattern by stepping through the array with a fixed stride > 1.
    // Here, we use a stride of 2 to access every other element, processing two locations per iteration.
    // The loop upper bound is adjusted to avoid out-of-bounds access.

    int stride = 2;
    int limit = n2 / stride;

    for (i = 0; i < limit; i++) {
        int pos = i * stride;  // Current base position for strided access
        w = c - n2 + pos;
        w = 1. - (w * w);

        // Apply computation at strided positions
        w_data[pos] = data[pos] * w;
        if (pos + 1 < n2) {
            w_data[pos + 1] = data[pos + 1] * w;  // Handle next element conditionally
        }

        // Mirror update using transformed index (similar to original -i-1 logic)
        int neg_idx = n2 - pos - 1;
        if (neg_idx >= 0 && neg_idx < n2) {
            w_data[neg_idx] = data[neg_idx] * w;
        }
    }
}
