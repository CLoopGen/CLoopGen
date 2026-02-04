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
    // Variant 2: Strided memory access with reversed row traversal (right-to-left)
    uint8_t *bs = bytestream;
    for (i = 0; i < h; i++) {
        for (j = w - 1; j >= 0; j--) {
            int byte_index = j >> 3;
            int bit_in_byte = 7 - (j & 7);
            *bs++ = (ptr[byte_index] >> bit_in_byte) & 1;
        }
        ptr += linesize;
    }
    bytestream = bs;
}
