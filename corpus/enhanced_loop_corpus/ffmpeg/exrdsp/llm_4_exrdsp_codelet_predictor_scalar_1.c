#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t size;
extern ptrdiff_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < size; i++) {
    uint8_t temp = src[i - 1] - 128;
    if (temp != 0) {
        src[i] += temp;
    }
}
}
