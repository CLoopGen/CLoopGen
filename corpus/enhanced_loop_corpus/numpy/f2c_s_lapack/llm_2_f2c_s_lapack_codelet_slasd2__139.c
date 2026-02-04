#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every other element in a rolled fashion)
    // We'll simulate a strided write pattern across ctot by using modulo arithmetic to wrap around.
    for (j = 0; j < 8; j += 2) {
        ctot[(j / 2) % 4] = 0;
    }
}
