#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k = 0;
    size_t r = 0;
    for (p = 0; p < size1; p++) {
        k += p;        // Accumulation creates loop-carried dependence (WAW on k)
        size_t temp = k * k;
        r = temp % 10; // WAR: r overwritten, but no dependency on previous r
        size_t c = p - (r > 0 ? 1 : 0); // RAW: c depends on r, but independent across iterations except via r
    }
}
