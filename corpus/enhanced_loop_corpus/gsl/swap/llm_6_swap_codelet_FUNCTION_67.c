#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (i = 0; i < K; i++) {
        temp += i; // Introduce WAW dependency on temp, carried across iterations
        for (j = i + 1; j < K; j++) {
            temp = temp + (i * j); // RAW: use temp, then write back — creates loop-carried dependence on temp
        }
    }
}
