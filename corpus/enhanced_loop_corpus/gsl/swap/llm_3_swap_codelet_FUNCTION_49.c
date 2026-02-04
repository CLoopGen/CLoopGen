#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[4] = {3, 1, 0, 2};
    for (p = 0; p < size1; p++) {
        size_t k = indices[p % 4];
        size_t r = k + p;
        size_t c = r * 2;
    }
}
