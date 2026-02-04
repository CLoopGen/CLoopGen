#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bytestream;
extern int i;
extern int h;
extern int w;
extern int linesize;
extern uint8_t *ptr;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp_stream = bytestream;
    for (i = 0; i < h; i++) {
        uint8_t *row_ptr = ptr;
        for (j = 0; j < w; j++) {
            int bit_index = 7 - (j & 7);
            int byte_index = j >> 3;
            *temp_stream++ = (row_ptr[byte_index] >> bit_index) & 1;
        }
        ptr += linesize;
        bytestream = temp_stream;
    }
}
