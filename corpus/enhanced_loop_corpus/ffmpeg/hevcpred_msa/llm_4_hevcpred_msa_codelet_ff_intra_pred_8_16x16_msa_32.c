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
    for (i = 0; i < 16; i++) {
        if (i % 2 == 0) {
            left[i] = src[-1 + stride * i];
        } else {
            left[i] = 0;
        }
    }
}
