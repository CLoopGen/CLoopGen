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
    // Variant 2: Consecutive array access using a local buffer copy
    // Pre-fetches the required bytes into a local array for contiguous access
    // Improves cache locality and separates pointer arithmetic from computation
    unsigned char local_buf[4];  // Assuming maximum nal_length_size <= 4
    nalsize = 0;
    // Copy data contiguously
    for (i = 0; i < nal_length_size; i++) {
        local_buf[i] = buf[(*buf_index)++];
    }
    // Process using consecutive access pattern
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | local_buf[i];
    }
}
