#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ac[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    int indices[4] = {1, 2, 3, 4}; // Define access order explicitly
    for (int j = 0; j < 4; j++) {
        int i = indices[j];
        ac[i] -= ac[i] * (0.00800000038F * i) * (0.00800000038F * i);
    }
}
