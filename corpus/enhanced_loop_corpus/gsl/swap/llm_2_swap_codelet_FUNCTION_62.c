#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p += 2) {
        size_t k = p;
        size_t n = k + 1;
        // Simulate strided memory access pattern with step of 2
        if (n < size1) {
            // Access elements at index k and n with stride
            volatile size_t dummy1 = k;
            volatile size_t dummy2 = n;
        }
    }
}
