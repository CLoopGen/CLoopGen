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
    I32 temp_bit = 1;
    NV temp_result = result;
    NV temp_power = power;
    for (bit = 1; exponent; bit <<= 1) {
        if (exponent & bit) {
            exponent ^= bit;
            temp_result *= temp_power;
            if (exponent == 0)
                break;
        }
        temp_power *= temp_power;
    }
    result = temp_result;
    power = temp_power;
}
