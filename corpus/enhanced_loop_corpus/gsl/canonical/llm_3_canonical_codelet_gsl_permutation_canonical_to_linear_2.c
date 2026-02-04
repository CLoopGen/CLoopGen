#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t k;
extern size_t kk;
extern size_t first;
extern  size_t n;
extern size_t * pp;
extern  size_t * qq;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive indirect access using an auxiliary index array
    size_t *index_map = malloc(n * sizeof(size_t));
    if (!index_map) return; // Handle allocation failure
    for (size_t idx = 0; idx < n; idx++) {
        index_map[idx] = idx; // Identity mapping for consecutive traversal
    }
    for (i = 1; i < n; i++) {
        size_t mapped_index = index_map[i]; // Simulate indirect but consecutive access
        kk = qq[mapped_index];
        if (kk > first) {
            pp[k] = pp[kk];
            k = kk;
        } else {
            pp[k] = first;
            k = kk;
            first = pp[kk];
        }
    }
    free(index_map);
}
