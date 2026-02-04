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
    int temp = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            temp += i + j; // Introduce RAW dependency: each read of temp depends on prior write
        }
    }
    // Eliminate loop-carried dependency by not exposing temp outside
    // No actual output, but dependency chain exists within the loop body
}
