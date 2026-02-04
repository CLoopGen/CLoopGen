#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t b;
extern uint64_t r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_a = a;
    uint64_t temp_r = r;
    for (i = 0; i < 4; i++) {
        temp_a <<= 16;
        temp_r = (temp_r << 16) | (temp_a / b);
        temp_a %= b;
    }
    a = temp_a;
    r = temp_r;
}
