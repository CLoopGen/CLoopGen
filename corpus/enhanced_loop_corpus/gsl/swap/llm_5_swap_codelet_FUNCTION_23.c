#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p++) {
        size_t k = p + 10;
        size_t r = k * 2;
        size_t c;

        if (r > 50) {
            c = r - p;
        } else {
            c = r + p;
        }

        if (c % 4 == 0) {
            p += 2;
        }
    }
}
