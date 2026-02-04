#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t size;
extern ptrdiff_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp = src[0];
    for (i = 1; i < size; i++) {
        uint8_t current = src[i];
        src[i] = temp + (src[i] & 127);
        temp = current;
    }
}
