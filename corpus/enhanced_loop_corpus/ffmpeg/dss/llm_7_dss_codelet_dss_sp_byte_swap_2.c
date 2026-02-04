#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 42 - 2; i += 2) {
        dst[i] = src[i + 4];
        dst[i + 1] = src[i + 5]; // Introduces WAW and RAW dependencies across iterations
    }
}
