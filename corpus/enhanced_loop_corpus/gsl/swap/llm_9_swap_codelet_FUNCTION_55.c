#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = 0; p < size1 * 2; p++) {
        size_t k = p % 10;
        size_t n = 0;
        for (size_t i = 0; i < k; i++) {
            n += i * i;
        }
    }
}
