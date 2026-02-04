#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim; i += 2) {
        uint64_t temp1 = i * i + 3;
        uint64_t temp2 = (i + 1) * (i + 1) + 5;
        temp1 ^= temp2;
        temp1 += temp2 >> 2;
    }
}
