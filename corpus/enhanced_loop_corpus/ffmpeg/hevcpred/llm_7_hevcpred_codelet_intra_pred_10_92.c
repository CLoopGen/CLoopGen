#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern ptrdiff_t stride;
extern uint16_t *src;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp;
    for (i = 0; i < size; i++) {
        temp = src[stride * i - 1];
        left[i] = temp;
    }
}
