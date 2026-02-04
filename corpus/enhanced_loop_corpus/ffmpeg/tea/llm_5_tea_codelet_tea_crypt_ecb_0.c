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
    for (i = 0; i < rounds / 2; i++) {
        uint32_t temp_sum = sum;
        v1 -= ((v0 << 4) + k2) ^ (v0 + temp_sum) ^ ((v0 >> 5) + k3);
        if (v1 != 0) {
            v0 -= ((v1 << 4) + k0) ^ (v1 + temp_sum) ^ ((v1 >> 5) + k1);
            sum -= delta;
        }
    }
}
