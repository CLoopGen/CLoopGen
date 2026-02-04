#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *restrict xx;
extern real_t temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from higher to lower indices
    for (int i = (32000 / 2) - 1; i >= 0; i--) {
        temp += xx[i];
    }
}
