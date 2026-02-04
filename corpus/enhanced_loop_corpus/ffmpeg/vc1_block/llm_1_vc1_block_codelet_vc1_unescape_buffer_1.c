#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int block_size = 4;
    int full_blocks = size / block_size;
    int remainder = size % block_size;

    for (int i = 0; i < full_blocks; i++) {
        for (int j = 0; j < block_size; j++) {
            *dst++ = *src++;
        }
    }
    for (int i = 0; i < remainder; i++) {
        *dst++ = *src++;
    }
}
