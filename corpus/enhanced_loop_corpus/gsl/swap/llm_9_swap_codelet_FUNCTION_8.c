#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1 * size1; p++) {
        size_t k;
        size_t n;
        for (k = 0; k < 5; k++) {
            n = (p + k) * (p + k);
            n = n ? n / (k + 1) : 1;
        }
    }
}
