#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array (simulated statically)
    // Use a simulated offset list (unrolled small case for realism)
    size_t offsets[8];
    size_t k = 0;
    for (i = 0; i < len && s[i]; ) {
        // Fill batch of offsets with sequential indices (indirect access pattern)
        size_t batch = 0;
        while (batch < 8 && i < len && s[i]) {
            offsets[batch++] = i++;
        }
        // Now traverse using indirect access
        for (size_t j = 0; j < batch; j++) {
            if (!s[offsets[j]]) {
                i = offsets[j]; // ensure i reflects correct termination point
                break;
            }
            i = offsets[j] + 1; // maintain forward progress
        }
        if (batch < 8) break; // finished early
    }
}
