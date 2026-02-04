#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (i = 0; i < size; i++) {
        temp = src[i];
        dst[i] = ((temp << 3) & 192) | ((temp << 3) & 56) | ((temp >> 5) & 7);
    }
}
