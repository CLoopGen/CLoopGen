#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (reverse order access via lookup)
    int indices[100];
    for (i = 0; i < 100; i++) {
        indices[i] = 99 - i;  // reverse mapping: 99, 98, ..., 0
    }
    for (i = 0; i < 100; i++) {
        int idx = indices[i];
        J[idx] = idx * 20;
    }
}
