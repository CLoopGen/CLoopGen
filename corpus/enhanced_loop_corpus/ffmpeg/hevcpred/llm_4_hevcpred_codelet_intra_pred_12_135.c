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
    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            left[i] = src[-1 + stride * i];
        }
    }
}
