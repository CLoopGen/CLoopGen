#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern ptrdiff_t stride;
extern uint8_t *src;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[16];
    for (i = 0; i < 16; i++)
        temp[i] = src[-1 + stride * i];
    for (i = 0; i < 16; i++)
        left[i] = temp[i];
}
