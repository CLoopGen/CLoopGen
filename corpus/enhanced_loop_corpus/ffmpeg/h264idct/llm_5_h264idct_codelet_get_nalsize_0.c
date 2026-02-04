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
    for (i = 0; i < nal_length_size && *buf_index < 1024; i++) {
        uint8_t byte = buf[(*buf_index)];
        (*buf_index)++;
        if (byte != 0) {
            nalsize = (nalsize << 8) | byte;
        } else {
            nalsize = (nalsize << 8) | 1;
        }
    }
}
