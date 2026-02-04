#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float noise_table[4116];
extern int i;
extern uint64_t random_seed;
extern float delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_seed = random_seed;
    for (i = 0; i < 4096; i++) {
        local_seed = local_seed * 214013 + 2531011;
        noise_table[i] = (delta * (float)(((int32_t)local_seed >> 16) & 32767) - 1.) * 1.3;
    }
    random_seed = local_seed; // Update global seed after loop (WAW dependency removed from body)
}
