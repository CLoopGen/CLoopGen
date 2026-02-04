#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Create a simulated indirection using an offset sequence
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute indirect indices: in this case, just sequential for realism, but enables pattern change
    for (size_t j = 0; j < len; j++) {
        indices[j] = j;
    }

    i = 0;
    for (; i < len; i++) {
        size_t idx = indices[i]; // Use indirect index
        if (idx >= len || !s[idx]) {
            // Found null terminator through indirect access
            i = idx; // Set i to actual position of '\0' or bound
            break;
        }
    }
    if (i == len) {
        i = len; // Ensure proper termination
    }

    free(indices);
}
