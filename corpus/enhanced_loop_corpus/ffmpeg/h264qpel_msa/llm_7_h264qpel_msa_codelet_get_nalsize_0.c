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
    int local_index = *buf_index;
    for (i = 0; i < nal_length_size; i++) {
        local_nalsize = (local_nalsize << 8) | buf[local_index];
        local_index++;
    }
    nalsize = local_nalsize;
    *buf_index = local_index;
}
