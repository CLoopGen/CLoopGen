#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p += 2) {
        size_t k = p * p;
        size_t r = (k + 1) % size1;
        size_t c;
        for (c = 0; c < r; c++) {
            k += (c * p) % 10;
        }
    }
}
