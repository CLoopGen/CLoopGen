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
    // Variant 2: Consecutive reverse-order access (backward traversal)
    int start_index = *buf_index + nal_length_size - 1;
    for (i = 0; i < nal_length_size; i++) {
        nalsize = ((unsigned int)nalsize << 8) | buf[start_index - i];
    }
    // Maintain consistent side effect: buf_index is advanced normally
    *buf_index += nal_length_size;
}
