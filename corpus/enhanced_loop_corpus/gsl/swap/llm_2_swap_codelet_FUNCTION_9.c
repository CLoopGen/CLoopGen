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
        r = p + 1; // Strided access with step of 2 (accessing consecutive even and odd indices)
        c = k + r;
    }
}
