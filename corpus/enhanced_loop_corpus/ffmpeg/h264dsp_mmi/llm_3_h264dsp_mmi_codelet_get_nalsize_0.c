#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nal_length_size;
extern  uint8_t *buf;
extern int *buf_index;
extern int i;
extern int nalsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index lookup table
    // Simulates irregular access pattern via precomputed indices
    int *indices = (int*)malloc(nal_length_size * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < nal_length_size; i++) {
        indices[i] = (*buf_index) + i; // Normally could be arbitrary order
    }
    nalsize = 0;
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[indices[i]];
    }
    *buf_index += nal_length_size; // Maintain consistent state update
    free(indices);
}
