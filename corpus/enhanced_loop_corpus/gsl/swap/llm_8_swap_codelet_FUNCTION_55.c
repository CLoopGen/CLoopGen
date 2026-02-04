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
        size_t n;
        k = p * p + 3;
        n = k % 7;
        if (n > 0) {
            n = n * n + k;
        }
    }
}
