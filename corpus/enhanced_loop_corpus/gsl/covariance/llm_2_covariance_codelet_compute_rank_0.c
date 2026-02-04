#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t j;
extern size_t k;
extern double rank;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (simulated with arithmetic stride on index)
    // Here we simulate a strided traversal by incrementing k by 2, processing elements with a stride of 2
    for (k = i; k < j; k += 2)
        rank += (k + 1.) + ((k + 1) < j ? (k + 2.) : 0.); // Add current and next effective value if in bounds
}
