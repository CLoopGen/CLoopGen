#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double * rlist;
extern  size_t n;
extern size_t k;
extern double result_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulating gather operation)
    result_sum = 0.0;
    size_t *indices = (size_t*)malloc(n * sizeof(size_t));
    if (!indices) return; // Early return on allocation failure
    for (size_t i = 0; i < n; i++) {
        indices[i] = i; // Populate index array in order (could be randomized or reordered in real use cases)
    }
    for (k = 0; k < n; k++) {
        result_sum += rlist[indices[k]];
    }
    free(indices);
}
