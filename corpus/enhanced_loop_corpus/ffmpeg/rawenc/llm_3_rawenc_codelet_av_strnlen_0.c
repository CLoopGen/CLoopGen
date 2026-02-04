#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate pointer array
    // Create a simulated indirect access pattern using a temporary index mapping
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute access indices in reverse order (indirect reversed access pattern)
    for (size_t j = 0; j < len; j++) {
        indices[j] = len - 1 - j;
    }

    i = 0;
    // Traverse original logical sequence using indirect addressing
    for (size_t idx = 0; idx < len; idx++) {
        size_t pos = indices[idx]; // Actual character position
        if (pos < i) break; // Ensure forward progress on i
        while (i <= pos) {
            if (i >= len || !s[i]) {
                free(indices);
                return;
            }
            i++;
        }
        if (!s[pos]) {
            i = pos; // Point i to the null terminator position
            break;
        }
    }
    // Final scan from current i to maintain correctness
    for (; i < len && s[i]; i++)
        ;

    free(indices);
}
