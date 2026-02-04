#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size; i += 3) {
        for (unsigned int j = i; j < i + 1; j++) {
            register uint8_t x = src[j + 2];
            dst[j + 1] = src[j + 1];
            dst[j + 2] = src[j + 0];
            dst[j + 0] = x;
        }
    }
}
