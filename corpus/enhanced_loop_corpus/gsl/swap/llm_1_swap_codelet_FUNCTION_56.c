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
        for (k = 0; k < size1 / 2; k++) {
            size_t r;
            for (r = 0; r < size1 / 4; r++) {
                size_t c;
            }
        }
    }
}
