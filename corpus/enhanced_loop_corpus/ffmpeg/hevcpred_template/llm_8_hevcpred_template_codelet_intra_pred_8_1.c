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
    for (i = 0; i < size; i += 2) {
        left[i] = src[-1 + stride * i];
        if (i + 1 < size) {
            left[i + 1] = src[-1 + stride * (i + 1)];
        }
    }
}
