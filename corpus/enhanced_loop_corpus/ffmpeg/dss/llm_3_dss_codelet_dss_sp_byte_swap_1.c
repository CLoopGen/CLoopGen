#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Increase the stride from 2 to 4 for sparser access pattern
    for (i = 3; i < 42; i += 4)
        dst[i] = src[i];
}
