#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile uint64_t temp = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            temp += i * j; // Eliminate memory-based dependencies; use only loop-invariant computation with reduction-style dependency (WAW on temp)
        }
    }
    // Prevent optimization of temp
    asm volatile("" : "+r"(temp));
}
