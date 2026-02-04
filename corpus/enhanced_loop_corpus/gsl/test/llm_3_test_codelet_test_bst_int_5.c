#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *data;
extern int *sorted_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with identity mapping)
    size_t i;
    // Simulate indirect addressing: indices[i] = i
    for (i = 0; i < n; ++i) {
        size_t idx = i; // Could be replaced by a lookup in an index array
        sorted_data[idx] = data[idx];
    }
}
