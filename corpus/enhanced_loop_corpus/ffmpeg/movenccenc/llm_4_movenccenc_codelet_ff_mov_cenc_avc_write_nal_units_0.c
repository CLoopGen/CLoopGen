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
    if (nal_length_size <= 0) return;
    for (j = 0; j < nal_length_size; j++) {
        nalsize = (nalsize << 8) | *buf_in++;
    }
}
