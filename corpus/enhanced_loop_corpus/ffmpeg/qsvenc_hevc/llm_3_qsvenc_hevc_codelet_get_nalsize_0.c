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
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    // Create a local index map assuming static size for demonstration (up to 4 bytes)
    int access_indices[4];
    int max_size = nal_length_size > 4 ? 4 : nal_length_size; // Limit for safety
    int j;
    for (j = 0; j < max_size; j++) {
        access_indices[j] = (*buf_index) + j; // indirect addressing setup
    }

    unsigned int temp_nalsize = 0;
    for (i = 0; i < max_size; i++) {
        temp_nalsize = (temp_nalsize << 8) | buf[access_indices[i]];
    }
    nalsize = temp_nalsize;
    *buf_index += max_size; // update buffer index by number of bytes consumed
}
