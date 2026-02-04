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
    // Variant 2: Consecutive reverse-order access from buf, reading backwards
    nalsize = 0;
    int start_index = *buf_index;
    for (i = 0; i < nal_length_size; i++) {
        // Access from the end of the current segment backwards
        int reverse_offset = nal_length_size - 1 - i;
        nalsize = ((unsigned int)nalsize << 8) | buf[start_index + reverse_offset];
    }
    // Advance buf_index as in original semantics
    *buf_index += nal_length_size;
}
