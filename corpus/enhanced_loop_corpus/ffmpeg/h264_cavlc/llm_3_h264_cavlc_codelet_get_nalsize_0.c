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
    // Variant 2: Consecutive forward access but using a local pointer for buffer
    // Improves locality and changes access pattern via pointer arithmetic
    uint8_t *local_buf = &buf[*buf_index];
    nalsize = 0; // Ensure nalsize starts clean
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | local_buf[i];
    }
    // Update the original buf_index to reflect advancement
    *buf_index += nal_length_size;
}
