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
    // Variant 2: Strided memory access (stride of 1, but accessing in reverse order)
    int start_idx = *buf_index + nal_length_size - 1;
    nalsize = 0;
    for (i = 0; i < nal_length_size; i++) {
        nalsize = (nalsize << 8) | buf[start_idx - i];
    }
    *buf_index = start_idx + 1;
}
