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
    for (i = 0; i < h; i++) {
        int offset = 0;
        for (j = 0; j < w; j++) {
            int bit_index = 7 - (j & 7);
            uint8_t byte_val = ptr[offset];
            *bytestream++ = (byte_val >> bit_index) & 1;
            if ((j & 7) == 7) offset++;
        }
        ptr += linesize;
    }
}
