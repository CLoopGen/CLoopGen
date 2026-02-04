#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    int indices[256];
    for (int i = 0; i <= 255; i++) {
        indices[i] = i;
    }
    for (int i = 0; in <= 255; i++, in++) {
        int idx = indices[i];
        table[idx] = out;
        table[-idx] = -out;
    }
}
