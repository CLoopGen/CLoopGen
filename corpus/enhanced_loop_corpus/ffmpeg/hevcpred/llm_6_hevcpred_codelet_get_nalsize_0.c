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
    int temp_nalsize = 0;
    for (i = 0; i < nal_length_size; i++) {
        unsigned int shifted = (unsigned int)temp_nalsize << 8;
        unsigned int byte_val = buf[(*buf_index)++];
        temp_nalsize = shifted | byte_val;
    }
    nalsize = temp_nalsize;
}
