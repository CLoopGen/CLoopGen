#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < K; i++) {
        temp += i;  // Introduce WAW dependency on temp, loop-carried dependency via accumulation
        for (j = 0; j < i; j++) {
            temp ^= (i + j);  // RAW dependency: temp depends on previous temp and loop indices
        }
    }
}
