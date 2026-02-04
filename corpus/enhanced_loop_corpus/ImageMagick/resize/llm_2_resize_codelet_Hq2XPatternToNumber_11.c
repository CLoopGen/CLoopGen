#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *pattern;
extern ssize_t i;
extern unsigned int result;
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping with modulo to stay in bounds)
    ssize_t stride = 2;
    for (i = 7; i >= 0; i--) {
        ssize_t index = (i * stride) % 8;  // Access pattern: map original index to strided position
        result += order * (unsigned int)pattern[index];
        order *= 2;
    }
}
