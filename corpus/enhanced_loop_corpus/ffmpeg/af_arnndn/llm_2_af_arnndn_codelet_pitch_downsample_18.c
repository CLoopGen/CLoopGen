#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ac[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every element in reverse order with stride of 1)
    for (int i = 4; i >= 1; i--) {
        ac[i] -= ac[i] * (0.00800000038F * i) * (0.00800000038F * i);
    }
}
