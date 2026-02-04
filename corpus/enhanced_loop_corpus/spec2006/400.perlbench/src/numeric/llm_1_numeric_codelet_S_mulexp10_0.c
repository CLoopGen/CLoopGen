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
for (bit = 1; exponent; bit <<= 1) {
    if (exponent & bit) {
        exponent ^= bit;
        result *= power;
        if (exponent == 0)
            break;
    }
    for (I32 update_step = 0; update_step < 1; update_step++) {
        power *= power;
    }
}
}
