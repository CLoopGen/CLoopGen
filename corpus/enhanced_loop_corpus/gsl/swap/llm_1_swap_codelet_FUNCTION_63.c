#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p += 2) {
        if (p >= size1) break;
        size_t k;
        size_t r;
        size_t c;
        for (size_t i = 0; i < 2 && p + i < size1; i++) {
            // Artificially unrolled body replicated up to two iterations
            k = p + i;
            r = k * 2;
            c = r / 2;
        }
    }
}
