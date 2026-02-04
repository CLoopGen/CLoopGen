#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int level;
extern int threshold[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 1, but accessed indirectly via index array to simulate potential future extension)
    int indices[5] = {4, 3, 2, 1, 0}; // Indirect addressing order
    double factor = 0.59999999999999998;
    for (int i = 0; i < 5; i++) {
        int idx = indices[i];
        threshold[idx] = threshold[idx + 1] * factor;
    }
}
