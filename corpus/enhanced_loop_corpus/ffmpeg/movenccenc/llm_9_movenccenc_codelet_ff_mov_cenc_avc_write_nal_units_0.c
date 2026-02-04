#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nal_length_size;
extern  uint8_t *buf_in;
extern int nalsize;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    nalsize = 0;
    for (j = 0; j < nal_length_size && j < 4; j++) {
        nalsize = (nalsize << 8) | (buf_in[j] & 0xFF);
    }
    // Unroll first two iterations when nal_length_size is known to be small
    if (nal_length_size >= 1) {
        nalsize = (nalsize << 8) | (buf_in[0] & 0xFF);
    }
    if (nal_length_size >= 2) {
        nalsize = (nalsize << 8) | (buf_in[1] & 0xFF);
    }
}
