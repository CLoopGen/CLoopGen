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
    random_seed = random_seed * 214013 + 2531011;
    int32_t val1 = (int32_t)random_seed >> 16;
    float term1 = (delta * (float)(val1 & 32767) - 1.0f) * 1.3f;

    random_seed = random_seed * 214013 + 2531011;
    int32_t val2 = (int32_t)random_seed >> 16;
    float term2 = (delta * (float)(val2 & 32767) - 1.0f) * 1.3f;

    random_seed = random_seed * 214013 + 2531011;
    int32_t val3 = (int32_t)random_seed >> 16;
    float term3 = (delta * (float)(val3 & 32767) - 1.0f) * 1.3f;

    random_seed = random_seed * 214013 + 2531011;
    int32_t val4 = (int32_t)random_seed >> 16;
    float term4 = (delta * (float)(val4 & 32767) - 1.0f) * 1.3f;

    noise_table[i]     = term1;
    noise_table[i + 1] = term2;
    noise_table[i + 2] = term3;
    noise_table[i + 3] = term4;
}
}
