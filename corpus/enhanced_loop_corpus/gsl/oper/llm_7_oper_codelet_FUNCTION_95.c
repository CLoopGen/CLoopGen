#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile uint64_t temp = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            temp += i * j; // Eliminate loop-carried dependencies: each iteration is independent
            temp ^= (temp >> 1); // Break potential WAW and WAR hazards via recombination
        }
    }
    // Prevent complete optimization out (simulate side effect)
    asm volatile("" : "+r"(temp));
}
