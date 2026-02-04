#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp;
extern float lpc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal (stride of -1)
    for (int i = 3; i >= 0; i--) {
        tmp = 0.899999976F * tmp;
        lpc[i] = (lpc[i] * tmp);
    }
}
