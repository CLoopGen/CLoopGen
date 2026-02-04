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
    int limit = w > 64 ? 64 : w;
    for (j = 0; j < limit; j += 4) {
        uint8_t byte_idx = j >> 3;
        uint8_t shift1 = 7 - (j & 7);
        uint8_t shift2 = 7 - ((j+1) & 7);
        uint8_t shift3 = 7 - ((j+2) & 7);
        uint8_t shift4 = 7 - ((j+3) & 7);
        *bytestream++ = (ptr[byte_idx] >> shift1) & 1;
        *bytestream++ = (ptr[byte_idx] >> shift2) & 1;
        *bytestream++ = (ptr[byte_idx] >> shift3) & 1;
        *bytestream++ = (ptr[byte_idx] >> shift4) & 1;
    }
    ptr += linesize;
}
}
