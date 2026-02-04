#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long mrand_list[56];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[55];
    for (int j = 1; j < 55; j++) {
        indices[j] = 55 - j; // Reverse access pattern
    }
    for (int j = 1; j < 55; j++) {
        int idx = indices[j];
        if (idx > 0) {
            mrand_list[idx] = (123413 * mrand_list[idx - 1]) % 9223372036854775807L;
        }
    }
}
