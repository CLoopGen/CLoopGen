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
for (i = 0; i < 4096; i++) {
    random_seed = random_seed * 214013 + 2531011;
    float value = (float)(((int32_t)random_seed >> 16) & 32767);
    if (((int)i & 15) < 8) {
        noise_table[i] = (delta * value - 1.f) * 1.3f;
    } else {
        noise_table[i] = (delta * (value * 0.5f) - 1.f) * 1.3f;
    }
}
}
