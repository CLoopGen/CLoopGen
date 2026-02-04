#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated with offset indexing)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    
    // Precompute indirect indices (simple sequential mapping for safety and realism)
    for (i = 0; i < len; i++) {
        indices[i] = i;
    }

    // Use indirect access through indices
    for (i = 0; i < len; i++) {
        size_t idx = indices[i];
        if (idx >= len || !s[idx]) {
            break;
        }
    }
    // Map final index back to original 'i'
    i = (i < len && s[indices[i]] == '\0') ? indices[i] : (i < len ? indices[i] + 1 : len);

    free(indices);
}
