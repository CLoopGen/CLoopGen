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
extern uint32_t sum;
extern uint32_t delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_sum = 0;
    uint32_t prev_v0 = v0, prev_v1 = v1;
    uint32_t next_v0, next_v1;
    for (i = 0; i < rounds / 2; i++) {
        local_sum += delta; // Introduce local accumulation to break WAW on global sum
        next_v0 = prev_v0 + ((prev_v1 << 4) + k0) ^ (prev_v1 + local_sum) ^ ((prev_v1 >> 5) + k1);
        next_v1 = prev_v1 + ((next_v0 << 4) + k2) ^ (next_v0 + local_sum) ^ ((next_v0 >> 5) + k3);
        prev_v0 = next_v0;
        prev_v1 = next_v1;
    }
    v0 = prev_v0;
    v1 = prev_v1;
    sum += local_sum; // Update global sum only once at the end
}
