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
    for (bit = 1; exponent > 0; bit <<= 1) {
        if (exponent & bit) {
            exponent -= bit; // Using subtraction instead of XOR for same effect but different operation
            result *= power;
            result *= power; // Double multiplication to increase arithmetic density
            if (exponent <= 0)
                break;
        }
        power *= power;
        if ((bit & 0xFF) == 0) // Skip some iterations artificially by increasing loop stride under condition
            bit += bit >> 4;  // Non-uniform step adjustment to alter effective trip count
    }
}
