#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  size_t size;
extern  gsl_permutation *p;
extern size_t i;
extern size_t k;
extern size_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index remapping array (simulating gather access)
    // Introduce an auxiliary index array to alter access order, creating irregular memory access
    size_t *indices = (size_t*)malloc(size * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Create a scrambled access order: reverse mapping
    for (i = 0; i < size; ++i) {
        indices[i] = size - 1 - i;
    }

    count = 0;
    size_t *data = p->data;

    for (i = 0; i < size; ++i) {
        size_t mapped_i = indices[i]; // Use remapped index
        k = data[mapped_i];

        // Emulate the while(k > i) { k = data[k]; } without while
        // Unroll potential chain traversal with bounded iterations
        for (size_t iter = 0; iter < 5; ++iter) {
            if (k <= mapped_i) break;
            if (k >= size) break;
            k = data[k];
        }

        if (k >= mapped_i) {
            count++;
        }
    }

    free(indices);
}
