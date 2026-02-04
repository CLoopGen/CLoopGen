#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp;
extern float lpc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[4] = {1, 3, 0, 2}; // Custom access order
    for (int i = 0; i < 4; i++) {
        tmp = 0.899999976F * tmp;
        lpc[indices[i]] = (lpc[indices[i]] * tmp);
    }
}
