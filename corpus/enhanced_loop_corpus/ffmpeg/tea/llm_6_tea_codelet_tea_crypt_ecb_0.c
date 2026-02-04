#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v0;
extern uint32_t v1;
extern int rounds;
extern uint32_t k0;
extern uint32_t k1;
extern uint32_t k2;
extern uint32_t k3;
extern int i;
extern uint32_t delta;
extern uint32_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_v0, temp_v1;
    for (i = 0; i < rounds / 2; i++) {
        temp_v0 = v0;
        temp_v1 = v1;
        v1 -= ((temp_v0 << 4) + k2) ^ (temp_v0 + sum) ^ ((temp_v0 >> 5) + k3);
        v0 -= ((temp_v1 << 4) + k0) ^ (temp_v1 + sum) ^ ((temp_v1 >> 5) + k1);
        sum -= delta;
    }
}
