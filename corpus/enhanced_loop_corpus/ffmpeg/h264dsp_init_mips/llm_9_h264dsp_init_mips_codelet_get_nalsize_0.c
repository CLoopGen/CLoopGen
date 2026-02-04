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
    unsigned int temp_nalsize = 0;
    int local_index = *buf_index;
    for (i = 0; i < nal_length_size && local_index < 1024; i++) {
        temp_nalsize = (temp_nalsize << 8) | buf[local_index++];
    }
    nalsize = temp_nalsize;
    *buf_index = local_index;
}
