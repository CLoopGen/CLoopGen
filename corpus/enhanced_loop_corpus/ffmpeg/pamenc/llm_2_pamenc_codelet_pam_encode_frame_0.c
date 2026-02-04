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
    // Variant 1: Consecutive memory access by precomputing bit stream in chunks
    uint8_t *temp = bytestream;
    for (i = 0; i < h; i++) {
        const uint8_t *row = ptr;
        for (j = 0; j < w; j += 8) {
            uint8_t byte = row[j >> 3];
            int bits_left = w - j;
            if (bits_left >= 8) {
                *temp++ = (byte >> 7) & 1;
                *temp++ = (byte >> 6) & 1;
                *temp++ = (byte >> 5) & 1;
                *temp++ = (byte >> 4) & 1;
                *temp++ = (byte >> 3) & 1;
                *temp++ = (byte >> 2) & 1;
                *temp++ = (byte >> 1) & 1;
                *temp++ = byte & 1;
            } else {
                for (int b = 0; b < bits_left; b++) {
                    *temp++ = (byte >> (7 - b)) & 1;
                }
            }
        }
        ptr += linesize;
    }
    bytestream = temp;
}
