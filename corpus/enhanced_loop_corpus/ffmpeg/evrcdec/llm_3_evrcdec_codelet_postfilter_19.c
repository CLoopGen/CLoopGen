#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern float temp[54];
extern float gain;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access (iterate from end to beginning)
    for (i = length - 1; i >= 0; i--) {
        temp[i] *= gain;
    }
}
