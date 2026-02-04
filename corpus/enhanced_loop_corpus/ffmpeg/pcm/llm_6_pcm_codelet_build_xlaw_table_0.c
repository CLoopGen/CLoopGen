#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *linear_to_xlaw;
extern int mask;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp1, temp2;
    for (; j < 8192; j++) {
        temp1 = (127 ^ (mask ^ 128));
        temp2 = (127 ^ mask);
        linear_to_xlaw[8192 - j] = temp1;
        linear_to_xlaw[8192 + j] = temp2;
    }
}
