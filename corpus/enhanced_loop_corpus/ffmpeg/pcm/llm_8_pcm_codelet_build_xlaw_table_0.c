#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *linear_to_xlaw;
extern int mask;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (; j < 8192; j += step) {
        uint8_t val1 = (127 ^ (mask ^ 128));
        uint8_t val2 = (127 ^ mask);
        linear_to_xlaw[8192 - j] = val1;
        linear_to_xlaw[8192 + j] = val2;
        if (j + 1 < 8192) {
            linear_to_xlaw[8192 - (j + 1)] = val1;
            linear_to_xlaw[8192 + (j + 1)] = val2;
        }
    }
}
