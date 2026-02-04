#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p += 2) {
        size_t k;
        size_t r;
        size_t c;
        k = p;
        r = k * 4; // Strided access pattern: step of 4 elements apart
        c = r + 1;
    }
}
