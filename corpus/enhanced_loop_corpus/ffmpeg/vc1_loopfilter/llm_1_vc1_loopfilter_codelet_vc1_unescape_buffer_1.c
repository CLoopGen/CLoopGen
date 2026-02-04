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
    dsize = 0;
    for (int block = 0; block < size; block += 8) {
        for (int i = block; i < block + 8 && i < size; i++, dsize++) {
            *dst++ = *src++;
        }
    }
}
