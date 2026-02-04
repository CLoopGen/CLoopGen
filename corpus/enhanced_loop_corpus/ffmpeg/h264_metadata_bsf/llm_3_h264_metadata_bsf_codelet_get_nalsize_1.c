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
    // Variant 2: Consecutive reverse-order memory access from current buf_index
    nalsize = 0;
    int start_index = *buf_index;
    for (i = nal_length_size - 1; i >= 0; i--) {
        nalsize = ((unsigned int)nalsize << 8) | buf[start_index + i];
    }
    *buf_index += nal_length_size;  // Maintain consistent side effect on buf_index
}
