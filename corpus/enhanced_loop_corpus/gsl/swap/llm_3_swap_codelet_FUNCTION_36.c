#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[3];
    for (p = 0; p < size1; p++) {
        size_t k;
        size_t r;
        size_t c;
        indices[0] = p;
        indices[1] = size1 - p - 1; // Reverse access (indirect via computed index)
        indices[2] = (p * 7) % size1; // Pseudo-random indirect access using modulo
        k = indices[0];
        r = indices[1];
        c = indices[2];
    }
}
