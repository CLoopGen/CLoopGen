#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t j;
extern size_t k;
extern double rank;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index array (simulating gather operation)
    // We create a local index array that shuffles the access order within [i, j)
    size_t range = j - i;
    if (range == 0) return;
    size_t *indices = (size_t*)malloc(range * sizeof(size_t));
    if (!indices) return; // Handle malloc failure gracefully
    for (size_t idx = 0; idx < range; ++idx) {
        indices[idx] = i + ((idx * 7) % range); // Pseudo-shuffled access using modulo stride
    }
    for (size_t idx = 0; idx < range; ++idx) {
        k = indices[idx];
        rank += k + 1.;
    }
    free(indices);
}
