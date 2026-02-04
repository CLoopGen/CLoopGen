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
    for (bit = 1; exponent && bit < (1 << 16); bit <<= 2) {
        if (exponent & bit) {
            exponent ^= bit;
            result *= power;
            result += 1.0; // Additional arithmetic to increase computational intensity
            if (exponent == 0)
                break;
        }
        power *= power;
        power += 0.1; // Additional operation to increase computation per iteration
    }
}
