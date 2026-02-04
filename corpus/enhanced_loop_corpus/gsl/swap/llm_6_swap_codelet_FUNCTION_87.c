#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < K; i++) {
    for (j = 0; j < i; j++) {
        K = i + j; // Introduce WAW dependency on K and loop-carried dependency: each iteration modifies K, which affects outer loop bound
    }
}
}
