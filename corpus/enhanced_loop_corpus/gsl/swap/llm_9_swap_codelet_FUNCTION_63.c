#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1 * 2; p++) {
        size_t k;
        size_t r;
        size_t c;
        k = p % (size1 + 1);
        r = (k * k) + (p / 2);
        c = (r % 50) * 3;
        if (c > k) {
            c -= k;
        }
    }
}
