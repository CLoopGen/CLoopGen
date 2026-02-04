#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__1;
extern integer j;
extern doublereal beta;
extern doublereal safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using strided access
    // Simulate a strided memory access pattern over an array with stride of 4
    volatile doublereal dummy_array[1024];
    const integer stride = 4;
    // Initialize base effect to ensure usage
    for (j = 1; j <= i__1 && (j * stride) < 1024; ++j) {
        beta *= safmin;
        dummy_array[j * stride] = beta; // Strided access: elements 4, 8, 12, ...
    }
    // Complete original logic if upper bound exceeded due to stride condition
    for (; j <= i__1; ++j) {
        beta *= safmin;
    }
}
