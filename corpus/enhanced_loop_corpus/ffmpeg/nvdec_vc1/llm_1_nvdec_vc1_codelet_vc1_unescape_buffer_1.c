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
    int i, j;
    int block_size = 1;
    for (i = 0; i < size; i += block_size) {
        for (j = i; j < i + block_size && j < size; j++) {
            *dst++ = *src++;
            dsize = j;
        }
    }
}
