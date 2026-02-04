#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access by precomputing sequential indices (as a proxy for irregular access)
    size_t *indices = malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (size_t j = 0; j < len; j++) {
        indices[j] = j; // Normally this could be shuffled or non-linear
    }
    i = 0;
    for (size_t j = 0; j < len; j++) {
        i = indices[j];
        if (!s[i]) break;
        if (i + 1 >= len) {
            i++;
            break;
        }
    }
    free(indices);
}
