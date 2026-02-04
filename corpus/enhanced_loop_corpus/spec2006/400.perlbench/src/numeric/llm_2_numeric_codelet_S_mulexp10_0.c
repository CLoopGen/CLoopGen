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
    // Variant 1: Strided memory-like access pattern simulation using an array-like power progression
    // Instead of directly modifying 'power', we simulate a strided access by indexing into virtual "steps"
    // We use exponent bits to control when updates occur, maintaining same logic but with stride emulation

    I32 temp_exponent = exponent;
    NV temp_result = result;
    NV temp_power = power;
    I32 bit = 1;

    NV power_sequence[32]; // Simulate precomputed power strides (like in table-based exponentiation)
    power_sequence[0] = temp_power;
    for (I32 i = 1; i < 32; ++i) {
        power_sequence[i] = power_sequence[i-1] * power_sequence[i-1];
    }

    for (bit = 1; temp_exponent; bit <<= 1) {
        I32 idx = 0;
        I32 b = bit;
        while (b > 1) { b >>= 1; idx++; } // compute log2(bit)

        if (temp_exponent & bit) {
            temp_exponent ^= bit;
            temp_result *= power_sequence[idx];
            if (temp_exponent == 0)
                break;
        }
    }

    result = temp_result;
}
