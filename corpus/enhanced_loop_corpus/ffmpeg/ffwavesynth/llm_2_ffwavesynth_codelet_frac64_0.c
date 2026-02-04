#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t b;
extern uint64_t r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint64_t temp_array[64];
    for (i = 63; i >= 0; i--) {
        // Strided memory access pattern: write to non-consecutive indices
        int index = (i * 5) & 63; // Stride of 5, modulo 64 to stay in bounds
        if (a >= (uint64_t)1 << 63 || a << 1 >= b) {
            r |= (uint64_t)1 << i;
            a = (a << 1) - b;
            temp_array[index] = a; // Use strided access to store intermediate values
        } else {
            a <<= 1;
            temp_array[index] = a;
        }
    }
    // Dummy use of temp_array to prevent optimization away
    r ^= temp_array[0];
}
