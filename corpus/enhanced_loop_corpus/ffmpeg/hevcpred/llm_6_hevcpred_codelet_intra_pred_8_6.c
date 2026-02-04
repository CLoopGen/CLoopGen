#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern ptrdiff_t stride;
extern uint8_t *src;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (i = 0; i < size; i++) {
        temp = src[-1 + stride * i];
        left[i] = temp;
    }
}
