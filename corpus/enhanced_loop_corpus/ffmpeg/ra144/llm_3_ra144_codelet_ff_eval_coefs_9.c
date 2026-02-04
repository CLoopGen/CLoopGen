#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    int indices[5] = {9, 7, 5, 3, 1}; // Odd indices accessed in descending order
    for (i = 0; i < 5; i++)
        coefs[indices[i]] >>= 4;
}
