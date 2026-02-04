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
    unsigned int local_nalsize = nalsize;
    for (i = 0; i < nal_length_size; i++) {
        uint8_t byte_val = buf[(*buf_index) + i];
        local_nalsize = (local_nalsize << 8) | byte_val;
    }
    *buf_index += nal_length_size;
    nalsize = local_nalsize;
}
