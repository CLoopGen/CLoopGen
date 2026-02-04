#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *data_delete;
extern int *sorted_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-contiguous or reordered access)
    // Assume we are accessing elements in reverse order as a form of indirect pattern
    size_t i;
    for (i = 0; i < n; ++i) {
        size_t rev_index = n - 1 - i; // Reverse indexing
        data_delete[i] = sorted_data[rev_index];
    }
}
