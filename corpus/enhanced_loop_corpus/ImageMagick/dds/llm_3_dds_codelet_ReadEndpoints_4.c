#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _BC7Colors {
    unsigned char r[6];
    unsigned char g[6];
    unsigned char b[6];
    unsigned char a[6];
} BC7Colors;

extern BC7Colors *endpoints;
extern size_t num_subsets;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    size_t total_elements = num_subsets * 2;
    size_t *indices = (size_t*)malloc(total_elements * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (size_t j = 0; j < total_elements; j++) {
        indices[j] = j; // Populate index map (could be shuffled or reordered in real use cases)
    }
    for (i = 0; i < total_elements; i++) {
        endpoints->a[indices[i]] = 255;
    }
    free(indices);
}
