#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (k = 3; k < 60; k += 1) {
        if (k % 2 == 1 && k < 42)
            dst[k] = src[k];
    }
}
