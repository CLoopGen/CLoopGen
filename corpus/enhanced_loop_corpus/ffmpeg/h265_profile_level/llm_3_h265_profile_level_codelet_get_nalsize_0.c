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
    // Variant 2: Indirect memory access via an index map (simulated with offset array)
    // Uses precomputed offsets to access buf indirectly, mimicking irregular access patterns.
    // We assume a local offset array based on i values for indirection.
    int offsets[4] = {0, 1, 3, 2}; // Example small lookup table for indirect indexing
    for (i = 0; i < nal_length_size && i < 4; i++) {
        int indirect_index = (*buf_index) + offsets[i];
        nalsize = ((unsigned int)nalsize << 8) | buf[indirect_index];
    }
    // Advance buf_index by the logical number of bytes consumed
    (*buf_index) += nal_length_size;
}
