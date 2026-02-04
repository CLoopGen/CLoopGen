#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short hex_digits[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t size = (ssize_t)(sizeof(hex_digits) / sizeof(*hex_digits));
    short temp_val = -1;
    for (i = 0; i < size; i++) {
        // Break direct memory dependency by using a local temporary
        // Remove potential RAW by isolating computation from memory access
        hex_digits[i] = temp_val; // Use invariant value, no data dependence on prior iteration
    }
    // Eliminate loop-carried dependencies completely — each iteration is independent and uses compile-time constant logic
}
