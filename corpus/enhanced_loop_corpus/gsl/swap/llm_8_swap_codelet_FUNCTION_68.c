#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K * K; i++) {
        uint64_t temp = i * i + 3 * i - 1;
        temp %= 1000;
    }
}
