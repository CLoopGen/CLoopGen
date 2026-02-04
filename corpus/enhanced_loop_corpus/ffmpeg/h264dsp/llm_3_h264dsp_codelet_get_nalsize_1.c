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
    // Variant 2: Strided memory access (stride of 1, but precomputed offset array to simulate indirect-like pattern)
    int offsets[4] = {0, 1, 2, 3}; // Assume maximum nal_length_size is 4
    nalsize = 0;
    int base_index = *buf_index;
    for (i = 0; i < nal_length_size; i++) {
        int access_index = base_index + offsets[i];
        nalsize = ((unsigned int)nalsize << 8) | buf[access_index];
    }
    *buf_index = base_index + nal_length_size; // Update index after loop
}
