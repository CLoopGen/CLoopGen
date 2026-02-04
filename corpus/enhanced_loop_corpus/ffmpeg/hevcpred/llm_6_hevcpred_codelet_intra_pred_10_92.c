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
    if (size > 0) {
        left[0] = src[stride * 0 - 1];
        for (i = 1; i < size; i++) {
            left[i] = src[stride * i - 1] + (left[i-1] & 0xFFFF);
        }
    }
}
