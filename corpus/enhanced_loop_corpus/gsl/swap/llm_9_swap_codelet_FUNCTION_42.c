#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1 * 2; p++) {
        size_t k = p % size1;
        size_t r = (k + p / size1) * 3;
        size_t c = (r * r + k) % (size1 + 1);
        k += r + c;
    }
}
