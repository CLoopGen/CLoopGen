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
    // Variant 2: Consecutive prefetch-style dual-index access
    int local_index = *buf_index;
    for (i = 0; i < nal_length_size && local_index < (*buf_index) + nal_length_size; i++, local_index++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[local_index];
    }
    *buf_index = local_index; // Update global index after loop
}
