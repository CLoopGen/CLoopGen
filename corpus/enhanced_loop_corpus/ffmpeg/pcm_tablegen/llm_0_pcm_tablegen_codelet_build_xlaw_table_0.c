#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *linear_to_xlaw;
extern int mask;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 2; i++) {
    for (; j < 4096; j++) {
        linear_to_xlaw[8192 - j] = (127 ^ (mask ^ 128));
        linear_to_xlaw[8192 + j] = (127 ^ mask);
    }
}
}
