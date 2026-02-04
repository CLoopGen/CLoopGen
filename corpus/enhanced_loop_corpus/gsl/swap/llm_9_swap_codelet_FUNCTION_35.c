#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1 * size1; p++) {
        size_t k = p + 1;
        size_t n = k * k * k;
        n -= k * 2;
        if (n > k) {
            n = k;
        }
    }
}
