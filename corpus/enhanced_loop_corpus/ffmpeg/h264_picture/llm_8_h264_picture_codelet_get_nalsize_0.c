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
    int shift = nal_length_size;
    nalsize = 0;
    for (i = 0; i < shift; i++) {
        nalsize <<= 8;
        nalsize |= buf[(*buf_index)++];
    }
}
