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
    // Variant 2: Consecutive local buffer staging before processing
    uint8_t local_copy[4]; // Assume max nal_length_size is small and fixed
    int copy_size = nal_length_size > 4 ? 4 : nal_length_size;

    // Stage data with consecutive load
    for (i = 0; i < copy_size; i++) {
        local_copy[i] = buf[(*buf_index)++];
    }

    // Process from local staged array consecutively
    nalsize = 0;
    for (i = 0; i < copy_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | local_copy[i];
    }
}
