#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1; p++) {
        size_t k;
        size_t n;
        for (size_t i = 0; i < 5; i++) {
            k = (k + i) % (size1 + 1);
            n = (n + k) % (size1 + 1);
        }
    }
}
