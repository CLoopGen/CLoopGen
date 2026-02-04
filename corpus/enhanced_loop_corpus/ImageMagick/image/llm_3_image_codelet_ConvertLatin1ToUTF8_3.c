#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // We simulate indirect access by treating content as a base and using increasing indices
    // to fetch values indirectly through offset calculation
    size_t i;
    size_t *indices = (size_t*)aligned_alloc(sizeof(size_t), sizeof(size_t) * 256);
    if (!indices) return; // Handle allocation failure

    // Precompute indirect indices (e.g., scrambled or non-linear access pattern)
    for (i = 0; i < 256; i++) {
        indices[i] = i; // Identity map here, but could be permuted for true indirect behavior
    }

    unsigned char *local_p = content;
    for (i = 0; local_p + indices[i] && *(local_p + indices[i]) != '\x00'; i++) {
        unsigned char val = *(local_p + indices[i]);
        length += (val & 128) != 0 ? 2 : 1;
    }

    free(indices);
}
