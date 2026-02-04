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
    int outer_i;
    for (outer_i = 0; outer_i < nal_length_size; outer_i++) {
        i = outer_i;
        nalsize = ((unsigned int)nalsize << 8) | buf[(*buf_index)++];
    }
}
