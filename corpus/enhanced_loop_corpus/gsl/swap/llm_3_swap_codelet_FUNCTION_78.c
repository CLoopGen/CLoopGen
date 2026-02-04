#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(size2 * sizeof(size_t));
    if (!indices) return;
    for (size_t idx = 0; idx < size2; idx++) {
        indices[idx] = idx;  // Precomputed index array for indirect access
    }
    for (i = 0; i < size1; i++) {
        for (j = i + 1; j < size2; j++) {
            size_t pos = indices[j];  // Indirect memory access via index array
        }
    }
    free(indices);
}
