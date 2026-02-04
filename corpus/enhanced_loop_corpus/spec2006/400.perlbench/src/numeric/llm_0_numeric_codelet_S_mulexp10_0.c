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
I32 outer_bit;
for (outer_bit = 1; outer_bit <= 32; outer_bit <<= 1) {
    for (bit = outer_bit; exponent && (exponent & bit); bit <<= 1) {
        exponent ^= bit;
        result *= power;
        if (exponent == 0)
            break;
        power *= power;
    }
}
}
