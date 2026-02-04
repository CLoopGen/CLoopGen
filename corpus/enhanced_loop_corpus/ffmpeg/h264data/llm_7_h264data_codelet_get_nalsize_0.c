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
    nalsize = 0;
    for (int j = nal_length_size - 1; j >= 0; j--) {
        nalsize |= ((unsigned int)buf[(*buf_index) + (nal_length_size - 1 - j)]) << (j * 8);
    }
    *buf_index += nal_length_size;
}
