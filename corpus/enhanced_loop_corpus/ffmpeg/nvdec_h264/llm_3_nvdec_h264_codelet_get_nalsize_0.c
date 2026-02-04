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
    // Variant 2: Indirect memory access via an index map (simulated with fixed offset table)
    // Uses a local array to define indirect access order (e.g., reverse or shuffled)
    int access_map[4]; // Support up to 4-byte length field; adjust if needed
    int base_index = *buf_index;
    nalsize = 0;

    // Create reverse-order access map to alter memory access pattern
    for (i = 0; i < nal_length_size; i++) {
        access_map[i] = base_index + (nal_length_size - 1 - i);
    }

    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[access_map[i]];
    }

    *buf_index = base_index + nal_length_size; // Move index forward sequentially
}
