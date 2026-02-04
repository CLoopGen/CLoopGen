#include <stdio.h>

#include <inttypes.h>

typedef int I32;

typedef double NV;

extern I32 exponent;
extern NV result;
extern NV power;
extern I32 bit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access pattern via unrolled array-style state progression
    // Use a fixed-size array to store intermediate powers accessed consecutively
    // Loop logic is preserved but mapped onto sequential array traversal

    I32 temp_exponent = exponent;
    NV temp_result = 1.0;
    NV powers[32];  // Store consecutive squaring results in array
    I32 num_powers = 0;

    NV base = power;
    for (I32 i = 0; i < 32 && temp_exponent >> i; ++i) {
        powers[num_powers++] = base;
        base *= base;
    }

    // Traverse bits using consecutive index instead of bit shifting in place
    for (I32 i = 0; i < num_powers; ++i) {
        if (temp_exponent & (1 << i)) {
            temp_result *= powers[i];
        }
    }

    result = temp_result;
}
