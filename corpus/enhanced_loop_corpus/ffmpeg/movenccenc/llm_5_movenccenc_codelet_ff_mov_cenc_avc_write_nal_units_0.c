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
    for (j = 0; j < nal_length_size; j++) {
        uint8_t byte = *buf_in++;
        if (byte == 0) continue;
        nalsize = (nalsize << 8) | byte;
    }
}
