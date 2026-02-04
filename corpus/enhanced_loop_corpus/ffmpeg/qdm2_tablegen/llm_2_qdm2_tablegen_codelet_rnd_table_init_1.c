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
    for (i = 0; i < 4096; i += 4) {
        int idx1 = i;
        int idx2 = i + 1;
        int idx3 = i + 2;
        int idx4 = i + 3;
        random_seed = random_seed * 214013 + 2531011;
        noise_table[idx1] = (delta * (float)(((int32_t)random_seed >> 16) & 32767) - 1.) * 1.3;
        random_seed = random_seed * 214013 + 2531011;
        noise_table[idx2] = (delta * (float)(((int32_t)random_seed >> 16) & 32767) - 1.) * 1.3;
        random_seed = random_seed * 214013 + 2531011;
        noise_table[idx3] = (delta * (float)(((int32_t)random_seed >> 16) & 32767) - 1.) * 1.3;
        random_seed = random_seed * 214013 + 2531011;
        noise_table[idx4] = (delta * (float)(((int32_t)random_seed >> 16) & 32767) - 1.) * 1.3;
    }
}
