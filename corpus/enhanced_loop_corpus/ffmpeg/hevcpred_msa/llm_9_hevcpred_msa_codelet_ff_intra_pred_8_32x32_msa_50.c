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
    uint8_t sum = 0;
    for (i = 0; i < 16; i++) {
        sum += src[-1 + stride * (2 * i)];
        left[i * 2] = sum;
        left[i * 2 + 1] = sum ^ src[-1 + stride * (2 * i + 1)];
    }
}
