#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double P[];
extern double num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    // We reverse the order and access P with a stride, simulating non-consecutive pattern
    int indices[] = {4, 2, 0, 3, 1}; // custom strided access order
    num = 1.0; // initialize accumulator if needed
    for (i = 0; i < 5; ++i) {
        num = x * num + P[indices[i]];
    }
}
