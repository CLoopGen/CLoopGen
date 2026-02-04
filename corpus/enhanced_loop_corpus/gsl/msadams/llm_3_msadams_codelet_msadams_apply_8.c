#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * l;
extern size_t ord;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order traversal
    // Alters memory access pattern by iterating backward, accessing elements consecutively in reverse
    for (i = ord - 1; i >= 1; i--) {
        l[i + 1] = (ord + 1) * l[i] / (i + 1);
    }
}
