#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Simulate indirect access by precomputing a sequence of indices accessed out of order
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < len; i++) {
        indices[i] = i; // Normally could be shuffled or reordered; here kept sequential but enables indirect pattern
    }
    i = 0;
    for (; i < len; i++) {
        size_t idx = indices[i];
        if (idx >= len || !s[idx]) {
            break;
        }
    }
    free(indices);
    // Finalize i as the offset in original string where null or limit was found
    // Re-scan from 0 to i to set i to correct value in terms of original logic
    for (i = 0; i < len && s[i]; i++)
        ;
}
