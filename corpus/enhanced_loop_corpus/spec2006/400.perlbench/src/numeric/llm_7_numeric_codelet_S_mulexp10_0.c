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
    I32 local_exponent = exponent;
    NV local_result = result;
    NV local_power = power;
    I32 local_bit = 1;
    for (; local_exponent; local_bit <<= 1) {
        if (local_exponent & local_bit) {
            local_exponent ^= local_bit;
            local_result *= local_power;
            if (local_exponent == 0)
                break;
        }
        local_power = local_power * local_power;
    }
    result = local_result;
    power = local_power;
    exponent = local_exponent;
    bit = local_bit;
}
