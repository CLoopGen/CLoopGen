#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t p_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    size_t sum = 0;
    for (i = 0; i < p_1; i++) {
        sum += i * i;
        k1 = sum; // Introduce WAW dependency on k1, updated every iteration
    }
}
